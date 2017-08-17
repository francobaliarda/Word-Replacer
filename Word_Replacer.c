#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ERASE_BUFFER	while((c=getchar())!='\n')
#define MAX_LENGTH	16
#define MAX_PATH_LENGTH		64
#define	SPACE	1
#define CHARACTER	2

int
main(){
	int c,pos=0;
	char oldWord[MAX_LENGTH],newWord[MAX_LENGTH],currentWord[MAX_LENGTH]="0",name[MAX_PATH_LENGTH];
	char state=SPACE;
	
	FILE * input;
	FILE * newFile;

	printf("Enter the name of the file: ");
	scanf("%s",name);
	ERASE_BUFFER;
	input=fopen(name,"r");
	if(input==NULL)
	{
		printf("The file has not been found.\n");
		return -1;
	}
	printf("Enter the word to replace: ");
	scanf("%s",oldWord);
	ERASE_BUFFER;
	printf("Enter the new word: ");
	scanf("%s",newWord);
	ERASE_BUFFER;
	
	newFile=fopen("Output.txt","w");
	if(newFile==NULL)
	{
		printf("An error has ocurred.\n");
		return -1;
	}
	while((c=fgetc(input))!=EOF)
	{
		switch(state)
		{
			case SPACE:
				if(isspace(c))
				{
					state=SPACE;
					fputc(c,newFile);
				}
				else
				{
					state=CHARACTER;
					currentWord[pos++]=c;
				}
				break;
			case CHARACTER:
				if(isspace(c))
				{
					if(strcmp(currentWord,oldWord)==0)
						fputs(newWord,newFile);
					else
						fputs(currentWord,newFile);
					memset(currentWord,0,MAX_LENGTH);
					pos=0;
					state=SPACE;
					fputc(c,newFile);
				}
				else
					currentWord[pos++]=c;
				break;
			default:
			{
				printf("An error ocurred during the execution of the program.\n");
				fclose(input);
				fclose(newFile);
				return -1;
			}
		}
	}
	
	fclose(newFile);
	fclose(input);
	rename("Output.txt",name);
}