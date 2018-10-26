#include <stdio.h>
#include <time.h>
#include <windows.h>

#define True 1

int main()
{

	int i, stringLen;

	printf("KeyLen: ");
	scanf("%d", &stringLen);

	char key[stringLen];

	srand(time(NULL));

	while(True)
	{
		for (i = 0; i < stringLen; ++i){
			key[i] = 32 + rand()%223;
		}
	
		printf("~#: %s\n", key);

		Sleep(50);

		system("cls");
	}

	return 0;
}

