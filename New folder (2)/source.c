#include "func.c"


struct dish
{
	int id;
	char name[50];
	int price;
	char detail[200];
};




int main(void)
{
	system("color 09");
	FILE *fp,*fp2;
	intro();
	char username[50] = {'a','d','m','i','n'};
	char pwd[50] = {'a','d','m','i','n'};
	char pwd_cfm[50];
	login(username,pwd);
	int choice,ed_id;
	DISPLAY:choice = option_display();
	bool check_id = false;
	struct dish dpt;
	switch(choice)
		{
			case 1:
				system("cls");
				printf("Please enter your new password:\t");
				pwd_input(pwd);
				printf("\nConfirm your password:\t");
				pwd_input(pwd_cfm);
				if(!strcmp(pwd,pwd_cfm)) printf("\nYou have successfully changed your password!"); 
				else printf("\nPasswords do not match. Confirmation failed.");
				printf("\n\nPress anykey to return to main menu...\t");
				getch();
				goto DISPLAY;
			case 2:
				system("cls");
				printf("\t\t\t\t\t--------------MENU----------------\n");
				fp= fopen("Menu.dat","rb");
				rewind(fp);
				while (fread(&dpt,sizeof(struct dish),1,fp))
				{
					printf("\n\n%d. ",dpt.id);
					printf("%s",dpt.name);
					printf("\n%s",dpt.detail);
					printf("\nPrice: $%d",dpt.price);
				}
				fclose(fp);
				printf("\n\nPress anykey to return to main menu...\t");
				getch();
				goto DISPLAY;	
			case 3:
				system("cls");
				printf("Edit course/dish by id:\t");
				scanf("%d",&ed_id); 
				fgetc(stdin);
				fp = fopen("Menu.dat","rb+");
				while(fread(&dpt,sizeof(struct dish),1,fp))
				{
					if(ed_id == dpt.id)
					{
						check_id =true;
						break;
					}
				}
				if (check_id == false)
				{
					printf("\nThe course's id does not exist... Press anykey to continue");
					getch();
				}
				else
				{
					printf("\nPress 1 to edit name, press 2 to edit detail and press 3 to edit price:\t"); 
					int c2;
					scanf("%d",&c2);
					fflush(stdin);
					fp2=fopen("temp.dat","wb");
					rewind(fp);
					while(fread(&dpt,sizeof(struct dish),1,fp))
					{
						if (dpt.id != ed_id) fwrite(&dpt,sizeof(struct dish),1,fp2);
						else
						{
							switch(c2)
							{
								case 1:
									printf("\nNew name:\t");
									user_input(dpt.name);
									fwrite(&dpt,sizeof(struct dish),1,fp2);
									break;
								case 2:
									printf("\nNew datail:\t");
									detail_input(dpt.detail);
									fwrite(&dpt,sizeof(struct dish),1,fp2);
									break;
								case 3:
									printf("\nNew price:\t");
									scanf("%d",&dpt.price);
									fgetc(stdin);
									fwrite(&dpt,sizeof(struct dish),1,fp2);
									break;
								default:
									printf("Invalid choice!");
									break;
							}
						}
					}
					fclose(fp2);
					fclose(fp);
					remove("Menu.dat");
					rename("temp.dat","Menu.dat");
				}
				printf("\n\nPress anykey to return to main menu...\t");
				getch();
				goto DISPLAY;	
			case 4:
				fp =fopen("Menu.dat","rb");
				int max_id =0;
				while(fread(&dpt,sizeof(struct dish),1,fp))
				{
					if (dpt.id> max_id) max_id = dpt.id;
				}
				fclose(fp);
				system("cls");
				printf("\n\t\t\t\t\t-----------------Add a course or a dish---------------");
				printf("\nPlease enter all information:\t");
				struct dish new_dpt;
				new_dpt.id = max_id+1;
				printf("\nName:\t");       
				user_input(new_dpt.name);	
				printf("\nDetail:\t");	   
				detail_input(new_dpt.detail);
				printf("\nPrice:\t");      
				scanf("%d",&new_dpt.price); 
				fp =fopen("Menu.dat","a+");
				fwrite(&new_dpt,sizeof(struct dish),1,fp);
				fclose(fp);
				printf("\n\nPress anykey to return to main menu...\t");
				getch();
				goto DISPLAY;
			case 5:
				system("cls");
				printf("Delete course/dish by id:\t");
				scanf("%d",&ed_id); 
				fgetc(stdin);
				fp = fopen("Menu.dat","rb+");
				while(fread(&dpt,sizeof(struct dish),1,fp))
				{
					if(ed_id == dpt.id)
					{
						check_id =true;
						break;
					}
				}
				if (check_id == false)
				{
					printf("\nThe course's id does not exist... Press anykey to continue");
					getch();
				}
				else
				{
					fp2=fopen("temp.dat","wb");
					rewind(fp);
					bool check_deletion = false;
					while(fread(&dpt,sizeof(struct dish),1,fp))
					{
						if(check_deletion == false)
						{
							if (dpt.id != ed_id) fwrite(&dpt,sizeof(struct dish),1,fp2);
							else check_deletion = true;
						}
						else
						{
							dpt.id-=1;
							fwrite(&dpt,sizeof(struct dish),1,fp2);
						}
					}
					fclose(fp2);
					fclose(fp);
					remove("Menu.dat");
					rename("temp.dat","Menu.dat");
				}
				printf("\n\nPress anykey to return to main menu...\t");
				getch();
				goto DISPLAY;
		}
	return 0;
}

