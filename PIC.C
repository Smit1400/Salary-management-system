/*
  K.J.Somaiya College of Engineering
  Branch - Computer
  Project made by :
  Smit Shah 1811051
  Raj  Shah  1811048
  Directed by - Vaibhav Vasani Sir
*/
#include<stdio.h>
#include<string.h>
#include<conio.h>
FILE *office;          //declaring file pointer
void add(int num)
{
	int count=0;
	char name[100],password[100],file[100],dil[]=":",point[]=".";
	char id[100],present[100];
	office=fopen("salary5.txt","a+");    // Opening the file
	for(count=0;count<num;count++)        // Loop for adding number of records in file
	{
		printf("\nEnter id : ");
		scanf("%s",id);
		printf("\nEnter name : ");
		scanf("%s",name);
		printf("\nEnter password : ");
		scanf("%s",password);
		printf("\nEnter the days he is present : ");
		scanf("%s",present);
		strcpy(file,"");  // for copying space to file

		 //for adding data to file

		strcat(file,id);
		strcat(file,dil);
		strcat(file,name);
		strcat(file,dil);
		strcat(file,present);
		strcat(file,dil);
		strcat(file,password);
		strcat(file,point);
		fprintf(office,"%s",file);    //storing data of file in office
	}
	fclose(office) ;//closing office
}
void showrecord()       //function for showing record
{
	char point[]=":.";
	char *info,*totRec,*rec;
	int col=0;
	long int size=0;
	office=fopen("salary5.txt","r");   // Opening file
	fseek(office,0,SEEK_END);          // for analysing the data
	size=ftell(office);               // Finding size of the file
	fseek(office,0,SEEK_SET);        // setting pointer to the start of the file
	fgets(info,size,office);         // getting file data and storing in info
	totRec=strtok(info,point);     // spliting the data at ":." and storing it in totRec
	printf("\t\t");
	while(totRec!=NULL) //Loop for displaying the data
	{
		if(col<4)
		{
			printf("%s\t\t",totRec);
			totRec=strtok(NULL,point);
			col++;
		}
		else
		{
			printf("\n\t\t");
			col=0;
		}
	}
	fclose(office);
}
/*
  K.J.Somaiya College of Engineering
  Branch - Computer
  Project made by :
  Smit Shah 1811051
  Raj  Shah  1811048
  Directed by - Vaibhav Vasani Sir
*/

void calculate()
{
	char* enter;
	char point[]=":.";
	char *info,*rec,*totRec;
	int col=0,present;
	long int salary;
	long int size=0;
	printf("\nEnter id of employee whose salary is to be calculated : ");
	scanf("%s",enter);
	office=fopen("salary5.txt","r");   // Opening file
	fseek(office,0,SEEK_END);          // for analysing the data
	size=ftell(office);               // Finding size of the file
	fseek(office,0,SEEK_SET);        // setting pointer to the start of the file
	fgets(info,size,office);         // getting file data and storing in info
	totRec=strtok(info,point);     // spliting the data at ":." and storing it in totRec
	while(totRec!=NULL) //Loop for displaying the data
	{
		if(strcmp(enter,totRec)==0)
		{
			col=0;
			while(col<2)
			{
				totRec=strtok(NULL,point);
				col++;
			}
			present=atoi(totRec);


			break;
		}
		else
		{
			totRec=strtok(NULL,point);
		}

	}
	present=31-present;
	salary=50000-(present*(50000/31)); //calculating salary
	printf("\n\t\tSalary of the respective input id number is : %ld\n",salary);
	fclose(office);
}
void main()
{
	int num;  //declaring num
	clrscr(); //clearing screen
	printf("\t\t\t**Salary Management System**\t\t\t\t");
	while(1)
	{
		int select;    //declaring select
		printf("\n\n\t\t1.Add record of a new employee . ");
		printf("\n\n\t\t2.Show all record.");
		printf("\n\n\t\t3.Calculate Salary of Employee.");
		printf("\n\n\t\t4.Exit . ");
		printf("\n\n\t\tChoose from above option : ");
		scanf("%d",&select);       //read select
		switch(select)
		{
			case 1:
			{
				printf("\n\t\tEnter number of record you want to add : ");
				scanf("%d",&num);
				add(num);   //calling add functon and passing num
				break;
			}
			case 2:
			{
				showrecord();   //calling showrecord
				break;
			}
			case 3:
			{
				calculate();  //calling calculate  function which calculates salary
				break;
			}
			case 4:
			{
				break;
			}
		}
		if (select==4)
		{
		  printf("\n\t\tPress enter to exit :");
		  break;
		}
		if (select==3)
		{
		 break;
		}
}
	getch();
}
/*
  K.J.Somaiya College of Engineering
  Branch - Computer
  Project made by :
  Smit Shah 1811051
  Raj  Shah  1811048
  Directed by - Vaibhav Vasani Sir
*/
