#include<stdio.h>
#include<windows.h>//gotoxy()
#include<conio.h>//Use for delay(),getch()etc.
#include<ctype.h>//use for toupper(), tolower(),etc.
#include<string.h>//Use for strcmp(),strcpy(),strlen(),etc.
#include<stdlib.h>
char ans=0; 
int ok;
int b, valid=0;
//FUNCTION DECLERATION
void WelcomeScreen(void);//WelcomeScreen function decleration
void Title(void);//Title function decleration
void MainMenu(void);//MainMenu function decleration
void LoginScreen(void);//LoginScreen function decleration
void Add_rec(void);//Add_rec function declaration
void func_list();//function to list the patient details 
void Search_rec(void);//Search_rec function declaration
void Edit_rec(void);//Edit_rec function declaration
void Dlt_rec(void);//Dlt_rec function declaration
void ex_it(void);//exit function declaration
void gotoxy(short x, short y) 
{
	COORD pos = {x, y};//sets co-ordinates in (x,y).
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//list of global variable

struct patient
{
	int age;
	char Gender;
	char First_Name[20];
	char Last_Name[20]; 
	char Contact_no[15];
	char Address[30];
	char Email[30];
	char Doctor[20];
	char Problem[20];
};
struct patient  p,temp_c;
main(void)
{
	WelcomeScreen();//Use to call WelcomeScreen function
	Title();//Use to call Title function
	LoginScreen();//Use to call Menu function
}
/* ************************************************* Welcome Screen ********************************************* */
void WelcomeScreen(void)//function for welcome screen
{
	printf("\n\n\n\n\n\n\n\t\t\t\t#########################################");
	printf("\n\t\t\t\t#\t\t WELCOME TO\t\t#");
	printf("\n\t\t\t\t#    HOSPITAL MANAGEMENT SYSTEM    #");
	printf("\n\t\t\t\t#########################################");
	printf("\n\n\n\n\n Press any key to continue......\n");
	getch();
	system("cls");//Use to clear screen
}
/* ************************************************* Title Screen ********************************************* */
void Title(void)//function for title screen
{
	printf("\n\n\t\t----------------------------------------------------------------------------------");
	printf("\n\t\t\t\t       XYZ HOSPITAL         ");
	printf("\n\t\t----------------------------------------------------------------------------------");
}
/* ************************************************* Main Menu ********************************************* */
void MainMenu(void)//function decleration
{
	system("cls");
	int choose;
	Title();// call Title function
	printf("\n\n\n\n\n\t\t\t\t1. Add Patients Record\n");
	printf("\n\t\t\t\t2. List Patients Record\n");
	printf("\n\t\t\t\t3. Search Patients Record\n");
	printf("\n\t\t\t\t4. Edit Patients Record\n");
	printf("\n\t\t\t\t5. Delete Patients Record\n");
	printf("\n\t\t\t\t6. Exit\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%i", &choose);
	switch(choose)//Add_rec function is called
	{
		case 1:
			Add_rec();
    		break;
  		case 2:
	    	func_list();
	    	break;
		case 3:
			Search_rec();//View_rec function is call
		   	break;
		case 4:
			Edit_rec();//Edit_rec function is call
			break;
		case 5:
			Dlt_rec();//Dlt_rec function is call
			break;
		case 6:
			ex_it();//ex_it function is call
	    	break;
		default:
			printf("\t\t\tInvalid entry. Please enter right option :)");
			getch();
	}
}
/* ************************************************* Exit Screen ********************************************* */
void ex_it(void)//function to exit
{
	system("cls");
	Title();
	printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :)");
	getch();	
}
/* ************************************************* Login Screen ********************************************* */
void LoginScreen(void)//function for login screen
{
	//list of variables	
	int e=0	;
	char Username[15];
	char Password[15];
	char original_Username[25]="ankit";
	char original_Password[15]="5626";
	do
	{
		printf("\n\n\n\n\t\t\t\tEnter your Username and Password :)");
		printf("\n\n\n\t\t\t\t\tUSERNAME:");
		scanf("%s",&Username);
		printf("\n\n\t\t\t\t\tPASSWORD:");
		scanf("%s",&Password);
		if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
		{
			printf("\n\n\n\t\t\t\t\t...Login Successfull...");
			getch();
			MainMenu();//call MainMenu function
			break;
		}
		else
		{
			printf("\n\t\t\tPassword in incorrect:( Try Again :)");
			e++;
			getch();
		}
	}while(e<=2);
	if(e>2)
	{
		printf("You have cross the limit. You cannot login. :( :(");
		getch();
	    ex_it();
	}
	system("cls");
}
/* **************************************ADD RECORD*******************************************/
void Add_rec(void)
{
	system("cls");
	Title();// call Title function
	//list of variables
	char ans;
	FILE*ek;//file pointer
	ek=fopen("Record2.dat","a");//open file in write mode
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Add Patients Record !!!!!!!!!!!!!\n");
	/* **************************First Name*********************************** */
	A:
	printf("\n\t\t\tFirst Name: ");
	scanf("%s",p.First_Name);
	p.First_Name[0]=toupper(p.First_Name[0]);
	if(strlen(p.First_Name)>20||strlen(p.First_Name)<2)
	{
		printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
		goto A;
	}
	else
	{
		for (b=0;b<strlen(p.First_Name);b++)
		{
			if (isalpha(p.First_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name contain Invalid character :(  Enter again :)");
			goto A;
		}
	}
	/* ********************************************** Last name ************************************************ */
	B:
	printf("\n\t\t\tLast Name: ");
    scanf("%s",p.Last_Name);
    p.Last_Name[0]=toupper(p.Last_Name[0]);
    if(strlen(p.Last_Name)>20||strlen(p.Last_Name)<2)
	{
		printf("\n\t Invalid :( \t The max range for last name is 20 and min range is 2 :)");
		goto B;
	}
	else
	{
		for (b=0;b<strlen(p.Last_Name);b++)
		{
			if (isalpha(p.Last_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Last name contain Invalid character :(  Enter again :)");
			goto B;
		}
	}   
	/* ******************************************* Gender ************************************************************** */	   
	do
	{
	    printf("\n\t\t\tGender[F/M]: ");
		scanf(" %c",&p.Gender);
		if(toupper(p.Gender)=='M'|| toupper(p.Gender)=='F')
		{
			ok =1;
		}
		else 
		{
			ok =0;
		}
        if(!ok)
	    {
	    	printf("\n\t\t Gender contain Invalid character :(  Enter either F or M :)");
    	}
	}while(!ok);
	/* ***************************************** Age ********************************************************************** */	
    printf("\n\t\t\tAge:");
    scanf(" %i",&p.age);    
    /* **************************************** Address ******************************************************************* */    
    do
    {
	    C:
	    printf("\n\t\t\tAddress: ");
	    scanf("%s",p.Address);
	    p.Address[0]=toupper(p.Address[0]);
	    if(strlen(p.Address)>20||strlen(p.Address)<4)
		{
			printf("\n\t Invalid :( \t The max range for address is 20 and min range is 4 :)");
			goto C;
		}
	}while(!valid);
	/* ******************************************* Contact no. ***************************************** */
	do
	{
		D:
	    printf("\n\t\t\tContact no: ");
	    scanf("%s",p.Contact_no);
	    if(strlen(p.Contact_no)>10||strlen(p.Contact_no)!=10)
		{
			printf("\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)");
			goto D;
		}
		else
		{
			for (b=0;b<strlen(p.Contact_no);b++)
			{
				if (!isalpha(p.Contact_no[b]))
				{
					valid=1;
				}
				else
				{
					valid=0;
					break;
				}
			}
			if(!valid)
			{
				printf("\n\t\t Contact no. contain Invalid character :(  Enter again :)");
				goto D;
			}
		}
	}while(!valid);
	/* ************************************************** Email ******************************************** */
	do
	{
	    printf("\n\t\t\tEmail: ");
	    scanf("%s",p.Email);
	    if (strlen(p.Email)>30||strlen(p.Email)<8)
	    {
	       printf("\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)");	
		}
	}while(strlen(p.Email)>30||strlen(p.Email)<8);
	/* ********************************************************* Problem *********************************************** */
	E:
	printf("\n\t\t\tProblem: ");
	scanf("%s",p.Problem);
	p.Problem[0]=toupper(p.Problem[0]);
	if(strlen(p.Problem)>15||strlen(p.Problem)<3)
	{
		printf("\n\t Invalid :( \t The max range for first name is 15 and min range is 3 :)");
		goto E;
	}
	else
	{
		for (b=0;b<strlen(p.Problem);b++)
		{
			if (isalpha(p.Problem[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Problem contain Invalid character :(  Enter again :)");
			goto E;
		}
	}
	/* ********************************************** Prescribed Doctor **************************************** */	
	F:
    printf("\n\t\t\tPrescribed Doctor:");
    scanf("%s",p.Doctor);
    p.Doctor[0]=toupper(p.Doctor[0]);
    if(strlen(p.Doctor)>30||strlen(p.Doctor)<3)
	{
		printf("\n\t Invalid :( \t The max range for first name is 30 and min range is 3 :)");
		goto F;
	}
	else
	{
		for (b=0;b<strlen(p.Doctor);b++)
		{
			if (isalpha(p.Doctor[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Doctor name contain Invalid character :(  Enter again :)");
			goto F;
		}
	}
    fprintf(ek," %s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);//ek file is closed
    sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
    	Add_rec();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
    	MainMenu();
		}
	    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}
/* **************************************VIEW RECORD*******************************************/
void func_list()
{
	int row;
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! List Patients Record !!!!!!!!!!!!!\n");
		gotoxy(1,15);
		printf("Full Name");
		gotoxy(20,15);
		printf("Gender");
		gotoxy(32,15);
		printf("Age");
		gotoxy(37,15);
		printf("Address");
		gotoxy(49,15);
		printf("Contact No.");
		gotoxy(64,15);
		printf("Email");
		gotoxy(88,15);
		printf("Problem");
		gotoxy(98,15);
		printf("Prescribed Doctor\n");
		printf("=================================================================================================================");
		row=17;
		while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
		{
			gotoxy(1,row);
			printf("%s %s",p.First_Name, p.Last_Name);
			gotoxy(20,row);
			printf("%c",p.Gender);
			gotoxy(32,row);
			printf("%i",p.age);
			gotoxy(37,row);
			printf("%s",p.Address);
			gotoxy(49,row);
			printf("%s",p.Contact_no);
			gotoxy(64,row);
			printf("%s",p.Email);
			gotoxy(88,row);
			printf("%s",p.Problem);
			gotoxy(98,row);
			printf("%s",p.Doctor);
			row++;
		}
	fclose(ek);
	getch();
	MainMenu();
}
void Search_rec(void)
{
	char name[20];
	system("cls");
	Title();// call Title function
	FILE *ek;
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Search Patients Record !!!!!!!!!!!!!\n");
	//gotoxy(12,8);
	printf("\n Enter Patient Name to be viewed:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
	{
		if(strcmp(p.First_Name,name)==0)
		{
			gotoxy(1,15);
			printf("Full Name");
			gotoxy(25,15);
			printf("Gender");
			gotoxy(32,15);
			printf("Age");
			gotoxy(37,15);
			printf("Address");
			gotoxy(52,15);
			printf("Contact No.");
			gotoxy(64,15);
			printf("Email");
			gotoxy(80,15);
			printf("Problem");
			gotoxy(95,15);
			printf("Prescribed Doctor\n");
			printf("=================================================================================================================");
			gotoxy(1,18);
			printf("%s %s",p.First_Name, p.Last_Name);
			gotoxy(25,18);
			printf("%c",p.Gender);
			gotoxy(32,18);
			printf("%i",p.age);
			gotoxy(37,18);
			printf("%s",p.Address);
			gotoxy(52,18);
			printf("%s",p.Contact_no);
			gotoxy(64,18);
			printf("%s",p.Email);
			gotoxy(80,18);
			printf("%s",p.Problem);
			gotoxy(95,18);
			printf("%s",p.Doctor);
			printf("\n");
			break;
		}
	}
	if(strcmp(p.First_Name,name)!=0)
  	{
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	}
	fclose(ek);
	L:
	getch();
	printf("\n\n\t\t\tDo you want to view more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Search_rec();
    }
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
		MainMenu();
    }
	else
    {
    	printf("\n\tInvalid Input.\n");
    	goto L;
    }
}
void Edit_rec(void)
{
	FILE *ek, *ft;
  	int i,b, valid=0;
  	char ch;
  	char name[20];
	system("cls");
  	Title();
 	ft=fopen("temp2.dat","w+");
	ek=fopen("Record2.dat","r");
	if(ek==NULL)
	{
		printf("\n\t Can not open file!! ");
		getch();
		MainMenu();
	}
    printf("\n\n\t\t\t!!!!!!!!!!!!!! Edit Patients Record !!!!!!!!!!!!!\n");
	gotoxy(12,13);
	printf("Enter the First Name of the Patient : ");
	scanf(" %s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	gotoxy(12,15);
	if(ft==NULL)
	{
		printf("\n Can not open file");
		getch();
		MainMenu();
	}
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
	{
		if(strcmp(p.First_Name, name)==0)
		{
			valid=1;
			gotoxy(25,17);
			printf("*** Existing Record ***");
			gotoxy(10,19);
			printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_no,p.Email,p.Problem,p.Doctor);
			gotoxy(12,22);	
			printf("Enter New First Name: ");
			scanf("%s",p.First_Name);    
			gotoxy(12,24);
			printf("Enter Last Name: ");
			scanf("%s",p.Last_Name);
			gotoxy(12,26);
			printf("Enter Gender: ");
			scanf(" %c",&p.Gender);
			p.Gender=toupper(p.Gender);
			gotoxy(12,28);				
			printf("Enter age: ");
			scanf(" %i",&p.age);
			gotoxy(12,30);
			printf("Enter Address: ");
			scanf("%s",p.Address);
			p.Address[0]=toupper(p.Address[0]);
			gotoxy(12,32);
			printf("Enter Contact no: ");
			scanf("%s",p.Contact_no);
			gotoxy(12,34);
			printf("Enter New email: ");
			scanf("%s",p.Email);
			gotoxy(12,36);
			printf("Enter Problem: ");
			scanf("%s",p.Problem);
			p.Problem[0]=toupper(p.Problem[0]);
			gotoxy(12,38);
			printf("Enter Doctor: ");
			scanf("%s",p.Doctor);
			p.Doctor[0]=toupper(p.Doctor[0]);
			printf("\nPress U charecter for the Updating operation : ");
			ch=getche();
			if(ch=='u' || ch=='U')
			{
				fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_no,p.Email,p.Problem,p.Doctor);
				printf("\n\n\t\t\tPatient record updated successfully...");
			}					
		}
		else
		{
			fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_no,p.Email,p.Problem,p.Doctor);	
		}
	}
	if(!valid) 
	{
		printf("\n\t\tNO RECORD FOUND...");
	}
	fclose(ft);
	fclose(ek);
	remove("Record2.dat");
   	rename("temp2.dat","Record2.dat");
	getch();
	MainMenu();		
}
void Dlt_rec()
{
	char name[20];
	int found=0;
	system("cls");
	Title();// call Title function
	FILE *ek, *ft;
	ft=fopen("temp_file2.dat","w+");
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Patients Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Patient Name to delete: ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);
	while (fscanf(ek,"%s %s %c %i %s %s %s %s %s", p.First_Name, p.Last_Name, &p.Gender,&p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
	{
		if (strcmp(p.First_Name,name)!=0)
		fprintf(ft,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
		else 
		{
			printf("%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
			found=1;
		}
	}//while loop ends
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		MainMenu();
	}
	else
	{
		fclose(ek);
		fclose(ft);
		remove("Record2.dat");
		rename("temp_file2.dat","Record2.dat");
		printf("\n\n\t\t\t Record deleted successfully :) ");
		getch();
		MainMenu();
	}
} 
        scanf("%d",&choice);//choice for option

        fflush(stdin);// used to clear the buffer or stream
        switch(choice)
        {
        case 1 : system("cls"); //Used for clearing the screen
                 add();//function call
                 break;

        case 2 : system("cls"); //Used for clearing the screen
                 view();//function call
                 break;

        case 3 : system("cls"); //Used for clearing the screen
                 search();//function call
                 break;

        case 4 : system("cls"); //Used for clearing the screen
                 edit();//function call
                 break;

        case 5 : system("cls"); //Used for clearing the screen
                 del();//function call
                 break;

        case 6 : Edit_file();//function call
                 break;

        default : system("cls"); //Used for clearing the screen
                printf("\n\nInvalid input , try again by using valid inputs");
        }
        printf("\n\n");
    }
    return 0;
}//main

//Definition
/*====FUNCTION - 1---> extract()=====*/

void extract()
{
    //the file pointer points to the file
    //fopen function is used to open a file
    FILE *ptr = fopen("PATIENTFILE.txt","r");//the file is opened in read mode
    if(ptr == NULL)
    {
        //If the file does not exist
        //it will create file
        //We can use it in next execution of the program
        ptr = fopen("PATIENTFILE.txt","w");
        fclose(ptr);//it is used to close the opened file
        printf("CAUTION!!\nNO FILE FOUND\nCREATING A FILE PATIENTFILE.txt\nExiting...\n\n\n");
        return ;
    }

    //fread function is used to read a file
    //the fread functions returns the number of elements read successfully
    //this number is stored in num
    num = fread(&x, sizeof(struct Patient_Record),100, ptr);
    fclose(ptr);
}

//Definition
/*====FUNCTION - 2---> Edit_file()=====*/

void Edit_file()
{
    //the file pointer points to the file
    //fopen function is used to open a file
    FILE *ptr = fopen("PATIENTFILE.txt","w");//the file is opened in write mode
    if(ptr == NULL)
    {
        printf("Error");
        exit(1);
    }
    //the fwrite function is used to edit the file
    fwrite(x, sizeof(struct Patient_Record),num, ptr);

    fclose(ptr);//it is used to close the opened file
    return;
}

//Definition
/*====FUNCTION - 3---> add() =====*/

//Function to add the details of the patient
void add()
{
    printf("\n\n");
    printf("Data already stored on system : %d\n\n",num);//details of patient already present
    printf("Enter the number of patient details to be entered  : ");//no. of details to be entered
    scanf("%d",&n);//input
    sum = n + num ;

    for(i = num , j = 0 ; i<sum ; i++)//input details of patient
    {
        printf("\n");

        fflush(stdin);// used to clear the buffer or stream
        printf("Enter patient's Name : ");
        gets(x[i].name);//input name

        fflush(stdin);// used to clear the buffer or stream
        printf("Enter patient's disease : ");
        gets(x[i].disease);//input disease

        fflush(stdin);// used to clear the buffer or stream
        printf("Enter patient's the age : ");
        scanf("%d",&x[i].age);//input age

        fflush(stdin);// used to clear the buffer or stream
        printf("Enter patient's cabin no : ");
        scanf("%d",&x[i].cabin_no);//input cabin_no

        fflush(stdin);// used to clear the buffer or stream
        printf("Enter patient's phone number : ");
        scanf("%lld",&x[i].phone_no);//input phone_no

        fflush(stdin);// used to clear the buffer or stream
        printf("\n");
        j++;
        a++;
        num++;
    }
}

//Definition
/*====FUNCTION - 4---> view() =====*/

//function to view the details of the patients
void view()
{
    for(i=0; i<num; i++)//to show all the details on screen of the patients
    {
        printf("\n");
        printf("Serial Number : %d\n",i);
        printf("Name : ");
        puts(x[i].name);
        printf("Disease : ");
        puts(x[i].disease);
        printf("Cabin no : %d\n",x[i].cabin_no);
        printf("Phone number : 0%lld\n",x[i].phone_no);
        printf("Age : %d",x[i].age);
        printf("\n\n");
    }
}

//Definition
/*====FUNCTION - 5---> edit() =====*/

void edit()// function for editing patient detail
{
    int q,p;
    fflush(stdin);// used to clear the buffer or stream

    printf("Do you want to edit details of patient?\n");
    printf("SELECT A OPTION\n\n");
    printf("1.Name\n");
    printf("2.Disease\n");
    printf("3.Age\n");
    printf("4.Cabin\n");
    printf("5.Phone no.\n\n");
    printf("OPTION SELECT : ");

    scanf("%d",&q);//option select

    if(q<=5)
    {
        printf("Enter the SERIAL NO. of that patient (0 - %d) : ",num-1);
        scanf("%d",&p);//serial number

        // for matching patient id and then making changes
        if(p<num)
        {
            if(q==1)
            {
                fflush(stdin);// used to clear the buffer or stream
                printf("Enter the new name : ");//to modify the name
                gets(x[p].name);

            }
            else if(q==2)
            {
                fflush(stdin);// used to clear the buffer or stream
                printf("Enter the new Disease : ");//to modify the Disease
                gets(x[p].disease);
            }
            else if(q==3)
            {
                fflush(stdin);// used to clear the buffer or stream
                printf("Enter the new Age : ");//to modify the Age
                scanf("%d",&x[p].age);
            }

            else if(q==4)
            {
                fflush(stdin);// used to clear the buffer or stream
                printf("Enter the new Cabin no : ");//to modify the Cabin no
                scanf("%d",&x[p].cabin_no);
            }

            else if(q==5)
            {
                fflush(stdin);// used to clear the buffer or stream
                printf("Enter the new Phone no : ");//to modify the Phone no
                scanf("%lld",&x[p].phone_no);
            }
        }
        else//error message on invalid entry
        {
            printf("\n\nInvalid Serial \nTry Again !!\n\n");
        }
    }
    else//error message on invalid entry
    {
        printf("\n\nInvalid option\nTry Again!!\n\n");
    }
}

//Definition
/*====FUNCTION - 6---> search() =====*/

void search()
{
    int s,h,f;
    char u[100];// temp variable for matching
    printf("By what title you want to search ?\n");
    printf("1.Serial no.\n2.Name\n3.Disease\n4.Cabin no.\n5.Phone no.\n6.Age\n\n");
    printf("OPTION SELECT : ");
    scanf("%d",&h);
    if(h==1)// search by serial no
    {
        printf("Enter Serial number of the patient : ");
        scanf("%d",&s);
        if(s<num)// printing details
        {
            printf("\n");
            printf("Serial Number : %d\n",s);
            printf("Name : ");
            puts(x[s].name);
            printf("Disease : ");
            puts(x[s].disease);
            printf("Cabin no : %d\nPhone number : 0%lld\nAge : %d",x[s].cabin_no,x[s].phone_no,x[s].age);
            printf("\n\n");
        }
        else
            printf("\n\nNot Found\n\n");//error message on invalid entry
    }
    else if(h==2)//  search by name
    {
        int f=1;
        fflush(stdin);// used to clear the buffer or stream
        printf("Enter your name : ");
        gets(u);
        fflush(stdin);// used to clear the buffer or stream
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].name)==0)// compare and find name and print details
            {
                printf("\n");
                printf("Serial Number : %d\n",g);
                printf("Name : ");
                puts(x[g].name);
                printf("Disease : ");
                puts(x[g].disease);
                printf("Cabin no : %d\nPhone number : 0%lld\nAge : %d",x[g].cabin_no,x[g].phone_no,x[g].age);
                printf("\n\n");
                f=0;

            }
        }
        if(f==1)
            printf("\nNot Found\n");//error message on invalid entry



    }
    else if(h==3)// search by disease name
    {
        int f=1;
        fflush(stdin);// used to clear the buffer or stream
        printf("Enter Disease : ");
        gets(u);
        fflush(stdin);// used to clear the buffer or stream
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].disease)==0)
            {
                printf("\n");
                printf("Serial Number : %d\n",g);
                printf("Name : ");
                puts(x[g].name);
                printf("Disease : ");
                puts(x[g].disease);
                printf("Cabin no : %d\nPhone number : 0%lld\nAge : %d",x[g].cabin_no,x[g].phone_no,x[g].age);
                printf("\n\n");
                f=0;
            }


        }
        if(f==1)
            printf("\nNot Found\n");//error message on invalid entry


    }
    else if(h==4)
    {
        int o=1;
        int f=1;
        printf("Enter Cabin number : ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].cabin_no)
            {
                printf("\n");
                printf("Serial Number : %d\n",g);
                printf("Name : ");
                puts(x[g].name);
                printf("Disease : ");
                puts(x[g].disease);
                printf("Cabin no : %d\nPhone number : 0%lld\nAge : %d",x[g].cabin_no,x[g].phone_no,x[g].age);
                printf("\n\n");
                o=0;
            }

        }
        if(o==1)
            printf("Not Found\n\n");//error message on invalid entry

    }
    else if(h==5)
    {
        int o = 1;
        long long f=1;
        printf("Enter Phone number : ");
        scanf("%lld",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].phone_no)
            {
                printf("\n");
                printf("Serial Number : %d\n",g);
                printf("Name : ");
                puts(x[g].name);
                printf("Disease : ");
                puts(x[g].disease);
                printf("Cabin no : %d\nPhone number : 0%lld\nAge : %d",x[g].cabin_no,x[g].phone_no,x[g].age);
                printf("\n\n");
                o=0;
            }

        }
        if(o==1)
            printf("Not Found");//error message on invalid entry
    }
    else if(h==6)
    {
        int o = 1;
        int f=1;
        printf("Enter Age : ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].age)
            {
                printf("\n");
                printf("Serial Number : %d\n",g);
                printf("Name : ");
                puts(x[g].name);
                printf("Disease : ");
                puts(x[g].disease);
                printf("Cabin no : %d\nPhone number : 0%lld\nAge : %d",x[g].cabin_no,x[g].phone_no,x[g].age);
                printf("\n\n");
                o=0;
            }

        }
        if(o==1)
            printf("Not Found\n\n");//error message on invalid entry

    }
    else
        printf("\n\nInvalid input\n\n");//error message on invalid entry


}

//Definition
/*====FUNCTION - 7---> del() =====*/

// for deleting record of patient
void del()
{
    int f,h;
    printf("Enter the SERIAL NUMBER of the patient that you want to delete : ");
    scanf("%d",&f);
    if(f<num)// to remove the whole record
    {       //it copies the data of (n+1)th storaged values to nth stored values

        printf("What do you want ?\n");
        printf("1.Remove the whole record\n2.Remove Name\n3.Remove Disease");
        printf("\n4.Remove age\n5.Remove Cabin\n6.Remove phone number\n\n OPTION SELECT : ");

        scanf("%d",&h);
        if(h==1)
        {
            while(f<num)
            {
                strcpy(x[f].name,x[f+1].name);
                strcpy(x[f].disease,x[f+1].disease);
                x[f].age=x[f+1].age;
                x[f].cabin_no=x[f+1].cabin_no;
                x[f].phone_no=x[f+1].phone_no;
                f++;
            }
            num--;
        }
        else if(h==2)// to remove name and in place of it display DELETED.
        {
            strcpy(x[f].name,"DELETED");

        }
        else if(h==3)// to remove disease and in place of it display DELETED.
        {
            strcpy(x[f].disease,"DELETED");
        }
        else if(h==4)// to remove age and in place of it display 0.
        {
            x[f].age=0;
        }
        else if(h==5)// to remove cabin and in place of it display 0.
        {
            x[f].cabin_no=0;
        }
        else if(h==6)// to remove phone no and in place of it display 0.
        {
            x[f].phone_no=0;
        }

    }
    else
        printf("\n\nInvalid Serial number\n");

}