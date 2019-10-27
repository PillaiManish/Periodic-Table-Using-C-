#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>

//VOID RECHOICE---NOT IN ARRANGED MANNER

//STRUCTURE //
struct PERIDOIC
{
char name[10];
char symbol[10];
int atm;
float atmwt;
}p,q;


//{ UNIVERSAL DECLARATION
	int n;
	FILE *fp,*fd;
	char feedback1[1000];

	//FUNCTION DECLARATION//
	void addelement();
	void head();
	void rechoice();
	void out();
	void invalid();
	void feedback();
	void searchname();
	void searchatm();
	void searchatmwt();
	void searchsym();
	void credits();

	int start();
	int how_to_search();

// }
void main()
{

M:
n=start();

switch (n)
{
case 1:n=how_to_search();  //Calling Function For How To harch//

       switch (n)
       {
       case 1: searchname();
	       rechoice();
	       break;

       case 2: searchsym();
	       rechoice();
	       break;

	case 3:searchatm();
	       rechoice();
	       break;

	case 4:searchatmwt();
	       rechoice();
	       break;


       default:invalid();
	       textbackground(CYAN);
	       textcolor(WHITE);
	       goto M;

       }

	break;
case 2: ADD:
	addelement();  //FUNCTION FOR ADDING//
	rechoice();    //FUNCTION FOR RECHOICE//
	break;

case 3:printf("\n You have selected to quit");
       delay(1000);
       out();
       break;



default:invalid();
	textbackground(CYAN);
	textcolor(WHITE);
	goto M;
	}

//not needed exit(); //FUNCTION OF EXIT
}

//FUNCTION DEFINING//

int start() //FUNCTION OF START
{
clrscr();
textbackground(CYAN);
textcolor(WHITE);
head();
printf("\n \n \n \n \n \n \n \t \t Enter the number") ;
printf("\n \n \n \n \t \t \t 1. Search the Elements \n \n \t \t \t 2. Add the Elements \n \n \t \t \t 3. Quit");
printf("\n \n \t \t \t ");
scanf("%d",&n) ;
return n;
}

int how_to_search()
{
clrscr();
       head();
       printf("\n \n \n \n \n \n \n Enter the Number on how you want to search the elements");
       printf("\n \n \n \n \t \t \t 1. Search by name \n \n \t \t \t 2. Search by symbol \n \n \t \t \t 3. Search by atomic number \n \n \t \t \t 4. Search by atomic weight");
       printf("\n \n \t \t \t ");
       scanf("%d",&n);
       return n;
}

void head()
{
clrscr();
textbackground(CYAN);
textcolor(WHITE);
printf(" \n \n \t \t \t \t PERIODIC TABLE");
printf("\n \t --------------------------------------------------------------");
}

void searchname()
{

	char sname[10];   //Declaration of string for searching by name//
	clrscr();
	head();

	textbackground(CYAN);
	textcolor(WHITE);


	printf("\n Enter the name of the elements you want to search-:");
	scanf("%s",&sname);

	sname[0]=toupper(sname[0]);

	fp=fopen("C:\\TURBOC3\\BIN\\PROJECT\\PERIODIC.txt","r");
	if(fp==NULL)
	{
	printf("There is no file name periodic table");
	}

	while(fread(&q,sizeof(q),1,fp))
	{
		if(strcmpi(q.name,sname)==0)
			{
			      clrscr();
			      head();
			      printf("\n \n \n \n \n \n \n The details of the element :");
			      printf("\n \n Name of the element: %s \n",q.name);
			      printf("\n Symbol of the element: %s \n",q.symbol);
			      printf("\n Atomic No. of the element: %d \n",q.atm);
			      printf("\n Atomic Weight of the element: %f \n",q.atmwt);
			}
		else
			printf("\n Not found");
	 }

	 fclose(fp);
	 getch();
	 return;
}

void searchsym()
{

	char ssym[2];   //Declaration of string for searching by symbol//

	clrscr();
	head();

	textbackground(CYAN);
	textcolor(WHITE);

	printf("\n Enter the name of the elements you want to search-:");
	scanf("%s",&ssym);

	ssym[0]=toupper(ssym[0]);

	fp=fopen("C:\\TURBOC3\\BIN\\PROJECT\\PERIODIC.txt","r");
	if(fp==NULL)
	{
	printf("There is no file name periodic table");
	}

	while(fread(&q,sizeof(q),1,fp))
	{
		if(strcmpi(q.symbol,ssym)==0)
			{
			      clrscr();
			      head();
			      printf("\n \n \n \n \n \n \n The details of the element :");
			      printf("\n \n Name of the element: %s \n",q.name);
			      printf("\n Symbol of the element: %s \n",q.symbol);
			      printf("\n Atomic No. of the element: %d \n",q.atm);
			      printf("\n Atomic Weight of the element: %f \n",q.atmwt);
			}
		else
			printf("\n Not found");
	 }

	 fclose(fp);
	 getch();
	 return;
}


void searchatm()
{

	int satm;   //Declaration of integer for searching by atomic number//

	clrscr();
	head();

	textbackground(CYAN);
	textcolor(WHITE);

	printf("\n Enter the name of the elements you want to search-:");
	scanf("%d",&satm);

	fp=fopen("C:\\TURBOC3\\BIN\\PROJECT\\PERIODIC.txt","r");
	if(fp==NULL)
	{
	printf("There is no file name periodic table");
	}

	while(fread(&q,sizeof(q),1,fp))
	{
		if(q.atm==satm)
			{
			      clrscr();
			      head();
			      printf("\n \n \n \n \n \n \n The details of the element :");
			      printf("\n \n Name of the element: %s \n",q.name);
			      printf("\n Symbol of the element: %s \n",q.symbol);
			      printf("\n Atomic No. of the element: %d \n",q.atm);
			      printf("\n Atomic Weight of the element: %f \n",q.atmwt);
			}
		else
			printf("\n Not found");
	 }

	 fclose(fp);
	 getch();
	 return;
}

void searchatmwt()
{

	float satmwt;   //Declaration of float for searching by atmoic weight//

	clrscr();
	head();

	textbackground(CYAN);
	textcolor(WHITE);

	printf("\n Enter the atomic weight of the elements you want to search-:");
	scanf("%f",&satmwt);

	fp=fopen("C:\\TURBOC3\\BIN\\PROJECT\\PERIODIC.txt","r");
	if(fp==NULL)
	{
	printf("There is no file name periodic table");
	}

	while(fread(&q,sizeof(q),1,fp))
	{
		if (q.atmwt==satmwt)
			{
			      clrscr();
			      head();
			      printf("\n \n \n \n \n \n \n The details of the element :");
			      printf("\n \n Name of the element: %s \n",q.name);
			      printf("\n Symbol of the element: %s \n",q.symbol);
			      printf("\n Atomic No. of the element: %d \n",q.atm);
			      printf("\n Atomic Weight of the element: %f \n",q.atmwt);
			}
		else
			printf("\n Not found");
	 }

	 fclose(fp);
	 getch();
	 return;
}

void addelement() 	//FOR ADDITION OF ELEMENTS//
{
	clrscr();
	textbackground(CYAN);
	textcolor(WHITE);

	fp=fopen("C:\\TURBOC3\\BIN\\PROJECT\\PERIODIC.txt","a");
	if(fp==NULL)
	{
	printf("There is no file name periodic table");
	}

       head();
       printf("\n \n \n \n \n \n \n Enter the details of the element you want to add:");
       printf("\n \n Name of the element: ");
       scanf("%s",p.name);
       printf("\n Symbol of the element: ");
       scanf("%s",p.symbol);
       printf("\n Atomic No. of the element: ");
       scanf("%d",&p.atm);
       printf("\n Atomic Weight of the element: ");
       scanf("%f",&p.atmwt);

       //PRINTING DETAILS TO FILE//


       fwrite(&p,sizeof(p),1,fp);
       fclose(fp);

       fclose(fp);

       textcolor(MAGENTA+BLINK);
       cprintf("Your data has been successfully saved");
       delay(1000);
       return;
}

void rechoice() //FUNCTION FOR RECHOICE
{
clrscr();
textbackground(CYAN);
textcolor(WHITE);
       cprintf("\n \n \n ENTER WHAT U WANT TO DO NOW \n PRESS \n 1: Main Menu \n 2: Add more \n 3: Feeback \n 4:Exit");
       cscanf("%d",&n);
	switch (n)
		{
		case 1: main();break;
		case 2: addelement();break;
		case 3: feedback();break;
		case 5: out();break;
		case 4: credits();break;
		default:invalid();
			delay(1000);
			rechoice();
			}

return;
}

void out()     //FUNCTION FOR EXIT
{
clrscr();
head();
printf("\n \n \n  THANK YOU FOR USING IT");
delay(1000);
printf("\n \n CREATED BY ALEX,FRESHIN,MANISH,NIRANJAN,SIDDHARTH");
delay(1000);
printf("\n \n \n Program will terminate shortly");
delay(1250);
return;
}

void invalid() //FUNCTION FOR INVALID
{
textcolor(RED+BLINK);
		cprintf("\n=================================INVALID INPUT==================================");
			       delay(1000);
			       return;
}


void feedback()
{
char feed[2000];
clrscr();
head();
printf("\n \n \n \n PLEASE GIVE YOUR FEEDBACK HERE");
printf("\n \n \t \t");

	fd=fopen("C:\\TURBOC3\\BIN\\PROJECT\\FEEDBACK.txt","a");
	if(fd==NULL)
	{
	printf("There is no file name FEEDBACK");}
	gets(feed);
	fprintf(fd,"\n -------------------------------------------------");
	fwrite(&feed,sizeof(feed),1,fd);
	fprintf(fd,"\n -------------------------------------------------");
	printf("\n Thank you for giving the feedback");

delay(1000);
out();
return;
}

void credits()
{
int i;
clrscr();
for(i=15;i>=1;i--)
{
gotoxy(20,i);
printf("\n \t \t \t \t  CREDITS \n");
printf("\n \t \t Flowchart Made by		Siddarth\n");
printf("\n \t \t Debugging Done by		Niranjan\n");
printf("\n \t \t Editing Done by		Freshin\n");
printf("\n \t \t Program Made by		Alex & Manish\n");
delay(650);
clrscr();
}
for(i=15;i>=1;i--)
{
gotoxy(20,i);
printf("\n \t \t \t \t SPECIAL THANKS \n");
printf("\n \t \t TO OUR PARENTS \t to bring us in this position\n");
printf("\n \t \t TO PILLAI COLLEGE \t to give us this opportunity\n");
printf("\n \t \t Prof. RANJITA MAAM \t to help us at each moment");
printf("\n \t \t TO EVERYONE \t who motivated us");
delay(650);
clrscr();
}

getch();
}

