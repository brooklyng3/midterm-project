#include "func.h"

void intro()
{
	system(CLS);
	printf("\t\t\t------------------------Group 10's project-----------------------------\n\n");
	printf("Topic: Mangage a restaurant\n\n\n");
	printf("Member:   1. Tran Thu Hien         - 22070560\n");
	printf("       	  2. Doan Duy Long         - 22070843\n");
	printf("       	  3. Nguyen Tran Hai Phong - 22070701\n");
	printf("       	  4. Nguyen Manh Tuan	   - 22071205\n\n\n");
	printf("Press ENTER to continue:\t");
	getchar();
}

void user_input(char ch[50])
{
	scanf(" %49[^\n]", ch);
}

void detail_input(char ch2[200])
{
	scanf(" %199[^\n]", ch2);
}

void pwd_input(char pwd[50])
{
	scanf(" %49[^\n\t]", pwd);
}

void login(char username[50],char pwd[50])
{
	char user_id[50];
	char user_pwd[50];
	bool check=false;
	while (!check)
	{
		system(CLS);
		printf("Please enter your username and password:\t");
		printf("\n\nUsername: ");
		user_input(user_id);
		printf("\nPassword: ");
		pwd_input(user_pwd);
		if (!strcmp(user_pwd,pwd) && !strcmp(username,user_id))
		{
			check =true;
			printf("\n\nLogin successful!");
		}
		else
		{
			printf("\n\nLogin failed! Incorrect username or password.");
			printf("\nPress anykey to try again, press 0 to exit\t");
			char c;
			if ((c=getchar()) == '0') exit(0);
		}
	}
}

int option_display()
{
	system(CLS);
	printf("\t\t\t----------Welcome to Hawksworth's restaurant---------- ");
	printf("\nPlease choose your operation:");
	printf("\n\n1. Change password");
	printf("\n2. View menu");
	printf("\n3. Edit course/dish");
	printf("\n4. Add course/dish");
	printf("\n5. Delete course/dish");
	printf("\n6. Calculate total price...");
	printf("\n7. Exit program");
	printf("\n\nYour choice:\t");
	int opt;
	scanf("%d",&opt);
	fgetc(stdin);
	return opt;
}
