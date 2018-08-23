#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#define DEPTH 2
#define SEED_URL "http://www.chitkara.edu.in"
#define MAX_URL_PER_PAGE 100
#define MAX_URL_SIZE 200
int count = 1;
void itoa(int num, char* result)
{
  int i = 0,rem;
  char temp[100];
  while(num != 0)
  {
    rem = num % 10;
    temp[i++] = rem + '0';
    num /= 10;
  }
  temp[i] = '\0';	int k = 0;
// printf("I: %d",i);
  for(int j = i-1; j >= 0; j--)
  {
    result[k++] = temp[j];
  }
  result[k] = '\0';
  
}

void Crawl();
void getPage(char *url);
void fileCreation(char *str)
{
	char path[100] = {0},ct[20];
	FILE *fp;
	strcat(path,"file/");
	itoa(count++,ct);
	strcat(path,ct);
	strcat(path,".txt");
	fp = fopen(path,"w");
	if(fp == NULL)	printf("NOT OPEN");
	else
	{
		fprintf(fp,"%s", str);
		printf("\nFILE COPIED\n");
		fclose(fp);
	}
}
void testDir(char *dir)
{
  struct stat statbuf;
  if ( stat(dir, &statbuf) == -1 ) 
  {
    fprintf(stderr, "-----------------\n");
    fprintf(stderr, "Invalid directory\n");
    fprintf(stderr, "-----------------\n");
    exit(1);
  }

  //Both check if there's a directory and if it's writable
  if ( !S_ISDIR(statbuf.st_mode) ) 
  {
    fprintf(stderr, "-----------------------------------------------------\n");
    fprintf(stderr, "Invalid directory entry. Your input isn't a directory\n");
    fprintf(stderr, "-----------------------------------------------------\n");
    exit(1);
  }

  if ( (statbuf.st_mode & S_IWUSR) != S_IWUSR ) 
  {
    fprintf(stderr, "------------------------------------------\n");
    fprintf(stderr, "Invalid directory entry. It isn't writable\n");
    fprintf(stderr, "------------------------------------------\n");
    exit(1);
  }
}
int urlValidation(char *url)
{
	char cmd[100] = {0};
	strcat(cmd,"wget --spider ");
	strcat(cmd,url);
	if(!system(cmd))
		return 1;
	else
		return 0;
}
void getPage(char *url)
{
	printf("URL :%s\n",url);
	char cmd[100] = {0};
	strcat(cmd,"wget -O ~/Desktop/Crawler/TEST/temp.txt ");
	strcat(cmd,url);
	system(cmd);
}
void stringParser(char *str)
{
	char *urlBuffer[MAX_URL_PER_PAGE];
	char s[] = "<a href=\0",*print = malloc(100 * sizeof(char)) ;
	int i = 0,j = 0,g = 0;int flag = 0,urlCount = 0;
	while(str[i++] != '\0')
    {
      if(s[j] == str[i])
      {
      	flag = 0;	g = 0;
        while(s[j] != '\0')
        {
         	if(s[j++] != str[i++])
            {
            	flag = 1;
            	break;
            }
        }
       	j = 0;
        if(flag != 1)
        {
        	g = 0;
        	while(str[i++] != '"');
        	while(str[i] != '"')
        	{
        		print[g++] = str[i++];
        	}
        	print[g] = '\0';
			// if(count < MAX_URL_PER_PAGE)
			// {
			// 	strcpy(urlBuffer[],)
			// }        
   //    //  printf("LINK: %s\n",print);
        }
      }
  	}
}
void Crawl()
{
	FILE *fp;
	long long int i = 0;
	char ch,str[999999];
	fp = fopen("TEST/temp.txt","r");
	if(fp == NULL)	printf("FILE NOT OPENED\n");
	else
	{
		ch = fgetc(fp);
		while(ch != EOF)
		{
			str[i++] = ch;
			ch = fgetc(fp);
		}
		str[i++] = '\0';
		fclose(fp);
		fileCreation(str);
		stringParser(str);
	}
}
int main(int argc,char *argv[])
{
	char cmd[100] = {0},filename[100] = {0},url[100] = {0};
	// printf("Enter Directory Name\n");
	// scanf("%s",filename);
	// strcat(cmd,"mkdir ");
	// strcat(cmd,filename);
//	if()
	// system(cmd);
//	cmd
//	strcat(cmd,"cd ");
//	strcat(cmd,filename);
//	system();
//	testDir(filename);
	//FOR URL VALIDATION
	//printf("%s",argv[1]);
	strcpy(url,argv[1]);
//	urlValidation(url);
	getPage(url);
	Crawl();
	return 0;
}