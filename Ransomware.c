#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <dirent.h>

int getSize(FILE *file);

int main()
{

	FILE *file;
	BYTE key[] = {"&HVGAnsm3|5dks90ja0hsd978&&çlakd"};
	char fileName[] = {"teste.txt"};
	char newFileName[] = {"t3st3.txt"};
	int fileSize;
	BYTE *fileData;
	int i, j = 0;

		file = fopen(fileName, "rb");

		fileSize = getSize(file);

		fileData = (BYTE *)malloc((fileSize+1)*sizeof(BYTE));
		fread(fileData, fileSize, 1, file);

		fclose(file);

		file = fopen(newFileName, "wb");

		for (i = 0; i < fileSize; ++i){
			fileData[i] = fileData[i] ^ key[j];
			if (j == strlen(key)){ j = 0; }
		}

		fwrite(fileData, 1, fileSize, file);

		free(fileData);
		fclose(file);
	return 0;
}


int getSize(FILE *file)
{
	if (file == NULL){
		return 1;
	}
	fseek(file, 0, SEEK_END);
	int fileSize = ftell(file);
	rewind(file);
	return fileSize;
}

