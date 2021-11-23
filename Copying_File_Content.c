#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *ptr1, *ptr2;
	char k, file1[500], file2[500];
	printf("Input the file name for reading\n");
	scanf("%s", file1);
	printf("Input the file name for writing\n");
	scanf("%s", file2);
	
	if(ptr1 = fopen(file1,"r"))	//File1 is opened for reading.
	{
		if(ptr2 = fopen(file2, "r"))	//Check if file2 already  exists.
		{
			printf("File is already there\n");
			exit(0);
		}
		else
		{
			ptr2 = fopen(file2, "w");	//File2 is opened for writing
			if(ptr2 == NULL)
			{
				printf("File cannot be opened %s \n", file2);
				exit(0);
			}
			
			//Read the contents from file1 and write it to file2
			for(k = fgetc(ptr1); k != EOF;k = fgetc(ptr1))
			{
				fputc(k,ptr2);
			}
			fclose(ptr1);	//Close File1
			fclose(ptr2);	//Close File2
			printf("Contents are written to %s \n", file2);
		}
	}
	else	//No such input file is there.
	{
		printf("No such input file exists\n");
		exit(0);
	}

	return 0;
}
