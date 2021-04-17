#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
struct user
{
char phonenumber[20];
char name[50];
float amount;
}s;
void addrecords();
void listrecords();
void modifyrecords();
void deleterecords();
char get;
int main()
{       
	char choice;



	system("cls");
	printf("\n\t\t------WELCOME TO THE TELECOM BILLING SYSTEM------");
	printf("\n\t\tPress Any Key To Continue...");
	Sleep(2000);
	getch();
    system("cls");
	while (1)
	{
		system("cls");
		printf("\n A : For Adding New Records.");
		printf("\n L : For Listing Records");
		printf("\n M : For Modifying Records.");
		printf("\n D : For Deleting Records.");
		printf("\n E : For Exit\n");
		printf("\n\n\n Enter You Choice: ");
		choice=getche();
		choice=toupper(choice);
		switch(choice)
		{
	
			case 'A':
				addrecords();break;
			case 'L':
				listrecords();break;
			case 'M':
				modifyrecords();break;
			case 'D':
				deleterecords();break;
			case 'E':
				system("cls");
				printf("\n\n\t\t\t\tTHANK YOU FOR USING OUR SERVICE.");
				Sleep(2000);
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\nPress Any key to continue");
				getch();
		}
	}
}
void addrecords()
{
	FILE *f;
	char pno[20];
	struct user s;
	f=fopen("D:/project/file.txt","ab+");
	if(f==0)

	{   f=fopen("D:/project/file.txt","wb+");
		system("cls");
		printf("Please Wait While We Configure Your Computer");
		printf("\nPress Any Key To Continue...");
		getch();
	}
	
		
				system("cls");
				printf("\n Enter Phone Number: ");
				scanf("%[^\n]",&pno);
				fflush(stdin);
					while(fread(&s,sizeof(s),1,f)==1)
					{
						if(strcmp(s.phonenumber,pno)==0)
						{
							printf("Record Is Already Exists, Press Any Key To Exit");
							fclose(f);
							getch();
							main();
						}
					}
				strcpy(s.phonenumber,pno);
				printf("\n Enter Name: ");
				fflush(stdin);
				scanf("%[^\n]",&s.name);
				printf("\n Enter Amount: ");
				scanf("%f",&s.amount);
				fwrite(&s,sizeof(s),1,f);
				fflush(stdin);
				system("cls");
				printf("1 Record Successfully Added");
				printf("\n Any Key To Exit ");
				getch();
	fclose(f);
}
void listrecords()
{
	FILE *f;
	int i;
	if((f=fopen("D:/project/file.txt","rb"))==NULL)
		exit(0);
	system("cls");
	printf("Phone Number\t\tUser Name\t\t\tAmount\n");
	for(i=0;i<79;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{
		printf("\n%-10s\t\t%-20s\t\tRs. %.2f /-",s.phonenumber,s.name,s.amount);
	}
	printf("\n");
	for(i=0;i<79;i++)
		printf("-");

fclose(f);
getch();
}
void deleterecords()
{
	FILE *f,*t;
	int i=1;
	char phonenumber[20];
	if((t=fopen("D:/project/temp.txt","w+"))==NULL)
	exit(0);
	if((f=fopen("D:/project/file.txt","rb"))==NULL)
	exit(0);
	system("cls");
	printf("Enter The Phone Number To Be Deleted From The Records: ");
	fflush(stdin);
	scanf("%[^\n]",phonenumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phonenumber,phonenumber)==0)
		{       i=0;
			continue;

		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{       system("cls");
		printf("Ooops !! Phone Number \"%s\" Not Found",phonenumber);
		remove("D:/project/file.txt");
		rename("D:/project/temp.txt","D:/project/file.txt");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("D:/project/file.txt");
	rename("D:/project/temp.txt","D:/project/file.txt");
	system("cls");
	printf("The Number %s Successfully Deleted!!!!",phonenumber);
	getch();
}

void modifyrecords()
{
	FILE *f;
	char phonenumber[20];
	long int size=sizeof(s);
	if((f=fopen("D:/project/file.txt","rb+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter Phone Number Of The User To Modify: ");
	scanf("%[^\n]",phonenumber);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phonenumber,phonenumber)==0)
		{
			system("cls");
			printf("\n Enter Phone Number: ");
			scanf("%s",&s.phonenumber);
			printf("\n Enter Name: ");
			fflush(stdin);
			scanf("%[^\n]",&s.name);
			printf("\n Enter Amount: ");
			scanf("%f",&s.amount);
			fseek(f,-size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	fclose(f);
}

