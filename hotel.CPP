#include<math.h>
#include<time.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>
#include<dos.h>
#include<fstream.h>
#include<ctype.h>
#include<string.h>
#include<iostream.h>
#include<process.h>
/**********************************************
	     GLOBAL VARIABLE
**********************************************/
int i=0;
 struct room
{int rn;
char st;
void disproom()
{cout<<"\nroom no:"<<rn;
cout<<"status"<<st;    }
};
struct dat
{int d,m,y;
void disp()
{cout<<d<<":"<<m<<":"<<y;}
void today()
{time_t currentTime;
  struct tm *localTime;
  time( &currentTime );
  localTime = localtime( &currentTime );
  d = localTime->tm_mday;
  m = localTime->tm_mon + 1;
  y = localTime->tm_year + 1900;   		    //GLOBAL CLASS OBJECTS
}};

 int  chkhot(char sname[20]) ;

/**********************************************
			  GLOBAL FUNTIONS
*********************************** ***********/

void startup();
int opening1();
void opening2();
void makehofile();
void places();


/**********************************************
CLASS TRAVELAGENCY  CONSISTING OF FUNTIONS
AND DATA MEMBERS RELATED TO HOTEL AND
TRANSPORTATION  RESERVATIONS.
**********************************************/
class travelagency
{
 private:

 char name[50],hotel[30],destination[40],add[80],flag1,flag2,trans[30];
 int not1,not2,nor,top,noc,top2;

 float price,price2;
 public:
 int nods;
 dat d;
 int toggle;
 void select();                                   //DATA MEMBERS IN PUBLIC AREA
 void assignprice();
 void resho();
 void showhotel();
 void viewhorec();
 void showhotelrec();
 void delhotelrec();                           //MEMBER FUNTIONS FOR HOTEL RESER.
 void searchhotrec();
 void transferhoteldata();
 void edithoteldata();
 void edithoteldata(char*,float);
 void transferhoteldata1();
 void datetoday();
 char * gname(){return name;}
}user,user1[100];
void travelagency::datetoday()
{time_t currentTime;
  struct tm *localTime;
  time( &currentTime );
  localTime = localtime( &currentTime );
  d.d = localTime->tm_mday;
  d.m = localTime->tm_mon + 1;
  d.y = localTime->tm_year + 1900;   }			    //GLOBAL CLASS OBJECTS



/*_____________________________________________________________________________________________************************************************************************************/

			/**********************************************
			CLASS TRAVELAGENCY   FUNTIONS DEFINED
			OUTSIDE THE CLASS.
y			**********************************************/

/*_____________________________________________________________________________________________************************************************************************************/
				/********************************
					   HOTEL RESERVATIONS
				********************************/



/**********************************************
FUNTION USED TO RESERVE HOTEL.
**********************************************/
void travelagency::resho()
{ price=0;
 clrscr();
  flag1='N';
  while(flag1!='Y')
  {

   clrscr();
   datetoday();
   gotoxy(46,23);d.disp();
   flag1=toupper(flag1);
   gotoxy(20,5);cout<<"Please Enter Information For Hotel Reservation";
   gotoxy(20,7);cout<<"Please enter the choice of your hotel......";
   gotoxy(25,9);cout<<"1: 5 Star";
   gotoxy(25,10);cout<<"2: 3 Star";
   gotoxy(25,11);cout<<"3: Normal"<<endl;
   gotoxy(26,12);cout<<"......";cin>>top;
   clrscr();


     assignprice();

   clrscr();


   gotoxy(15,2);cout<<"PLEASE FILL IN THE DETAILS ...";
   gotoxy(25,5);cout<<"HOTEL RESERVATION FORM";
   gotoxy(5,8);cout<<"Name: ";
   gotoxy(5,10);cout<<"Address: ";
   gotoxy(5,12);cout<<"No of days: ";
   gotoxy(30,12);cout<<"Name of Hotel: ";
   if(top==1)
  { gotoxy(46,12);cout<<"Grand palace"; strcpy(hotel,"Grand palace");price=10000;}
   else if (top==2)
 {  gotoxy(46,12);cout<<"BEST INN"; strcpy(hotel,"Best inn");price=6000;}
   else
  { gotoxy(46,12);cout<<"ABC guest house "; strcpy(hotel,"Abc guest house");price=3000;}
   gotoxy(10,22);cout<<"Is the information correct(y/n)?? ";
   gotoxy(10,8);gets(name);
   gotoxy(13,10);gets(add);
   gotoxy(13,12);cin>>nods;
   price=price*nods;
   gotoxy(45,22);cin>>flag1;
   flag1=toupper(flag1);
   clrscr();
   datetoday();
   gotoxy(15,13);cout<<"Check in date ";
   gotoxy(15,15);d.disp();
   getch();
  }


 showhotel();
}


/**********************************************
FUNTION USED TO SHOW HOTEL RESERVATIONS.
**********************************************/

void travelagency::showhotel()
{
  int a,b;

   if(toggle==1)
 {
 clrscr();
 textcolor(WHITE);
 textbackground(BLUE);
 for(int h=25;h<50;h++)
 {
 gotoxy(20,8);cout<<"Please wait while we make the Reservation";
 gotoxy(h,12);cout<<"x";
 delay(250);
 }
 toggle=0;
 }

   clrscr();
   gotoxy(25,5);cout<<"Hotel     Reservation  ";
   gotoxy(24,6);cout<<"-----------------------";
   gotoxy(15,8);cout<<"Name:"<<strupr(name);
   gotoxy(15,10);cout<<"Address:"<<strupr(add);
   gotoxy(15,12);cout<<"Name of the hotel:  "<<strupr(hotel)
		     <<" , "<<strupr(destination);
   gotoxy(15,20);cout<<"Your Reservations have been done"
			"Please pay the Amount!!!";
   gotoxy(25,22);cout<<"Amount: Rs."<<setprecision(2)<<price;
   gotoxy(17,15);cout<<"Check in date: "<<d.d<<":"<<d.m<<":"<<d.y;
   gotoxy(17,16);cout<<"Check out after "<<nods<<" days";
   if(price2)
   {gotoxy(25,23);cout<<"Restaurant amount ="<<price2;}
   getch();

}


/**********************************************
FUNTION USED TO VIEW HOTEL RECORDS.
**********************************************/
void travelagency::viewhorec()
{

 int option;

  while(option!=5)
  {
   clrscr();
   gotoxy(24,5);cout<<"HOTEL RESERVATION INFORMATION";
   gotoxy(25,10);cout<<"choose.....";
   gotoxy(25,12);cout<<"1: View hotel reservation records";
   gotoxy(25,14);cout<<"2: Delete a particular record";
   gotoxy(25,16);cout<<"3: Search for a record";
   gotoxy(25,18);cout<<"4: Edit a record ";
   gotoxy(25,20);cout<<"5: Exit.....  ";
   cin>>option;

    switch(option)
    {
     case 1:showhotelrec();
	    break;
     case 2:delhotelrec();
	    break;
     case 3:searchhotrec();
	    break;
     case 4:edithoteldata();
	    break;
    }
  }
}


/**********************************************
FUNTION USED TO SHOW ALL HOTEL RESERVATIONS.
**********************************************/
void travelagency::showhotelrec()
{

fstream fil1;

fil1.open("hotel.dat",ios::binary|ios::in);
int flag=0;
 while(fil1.read((char*)&user,sizeof (user)))
 {user.showhotel();
 flag++;}
 if(flag==0)
{clrscr();
gotoxy(10,12);cout<<"NO RESERVATIONS ";}
fil1.close();
getch();
}

int gd(dat d1,dat d2)
{

	int days_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int years_difference, days_difference;

	int months_total;

	int reg_year = 365;



	/////////////////////////////Years/////////////////////////////////


	if(d1.y == d2.y)
	{
		years_difference = 0;
	}
	else
	{
		if(d1.y % 4 == 0 && d2.y % 100 != 0 || d1.y % 400 == 0)
		{
			if(d2.y % 4 == 0 && d2.y % 100 != 0 || d2.y % 400 == 0)
			{
				if(d1.y > d2.y)
				{
					years_difference = (d1.y - d2.y) * (reg_year) + 2;
				}
				else
				{
					years_difference = (d2.y - d1.y) * (reg_year) + 2;
				}
				if(d1.m > d1.m)
				{
					if(days_in_months[d1.m - 1] > days_in_months[1])
					{
						--years_difference;
					}
				}
			}
			else
			{
				if(d1.y > d2.y)
				{
					years_difference = (d1.y - d2.y) * (reg_year) + 1;
				}
				else
				{
					years_difference = (d2.y - d1.y) * (reg_year) + 1;
				}
				if(d1.m > d2.m)
				{
					if(days_in_months[d2.m - 1] > days_in_months[1])
					{
						--years_difference;
					}
				}
			}
		}
		else
		{
			if(d1.y > d2.y)
			{
				years_difference = (d1.y - d2.y) * (reg_year);
			}
			else
			{
				years_difference = (d2.y - d1.y) * (reg_year);
			}
		}
	}

	/////////////////////////////Months////////////////////////////////////


	if(d1.m == d2.m)
	{
		months_total = 0;
	}
	else
	{
		if(d1.m > d2.m)
		{
			for(int i = (d1.m - 1); i > (d2.m - 1); i--)
			{
				static int months_total_temp = 0;
				months_total_temp += days_in_months[i];
				months_total = months_total_temp;
			}
		}
		else
		{
			for(int i = (d1.m - 1); i < (d2.m - 1); i++)
			{
				static int months_total_temp = 0;
				months_total_temp += days_in_months[i];
				months_total = months_total_temp;
			}
		}
	}

	////////////////////////////Days//////////////////////////////////

	int days_total;

	if (d1.d == d2.d)
	{
		days_difference = 0;
		days_total = (years_difference + months_total) - days_difference;
	}
	else
	{
		if(d1.d > d2.d)
		{
			days_difference = d1.d - d2.d;
			days_total = (years_difference + months_total) - days_difference;
		}
		else
		{
			days_difference = d2.d - d1.d;
			days_total = (years_difference + months_total) + days_difference;
		}
	}

	//////////////////////////In Between Leap Years///////////////////////////////

	if(d1.y == d2.y)
	{
	}
	else
	{
		if(d1.y > d2.y)
		{
			for(int i = (d2.y + 1); i < d1.y; i++)
			{
				if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
				{
					cout<<endl;
					cout<<i<<endl;
					++days_total;
				}
			}
		}
		else
		{
			for(int i = (d1.y + 1); i < d2.y; i++)
			{
				if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
				{
					cout<<endl;
					cout<<i<<endl;
					++days_total;
				}
			}
		}
	}





	return days_total;

}




/*int gd(dat dt1, dat dt2)
{

    long int n1 = dt1.y*365 + dt1.d;
    for (int i=0; i<dt1.m - 1; i++)
	n1 += monthDays[i];

    n1 += countLeapYears(dt1);


    long int n2 = dt2.y*365 + dt2.d;
    for (int j=0; j<dt2.m - 1; j++)
	n2 += monthDays[i];
    n2 += countLeapYears(dt2);

    return (n2 - n1);
}

  */


/**********************************************
FUNTION USED TO DELETE A HOTEL RECORD.
**********************************************/
void datedel()
{  dat d5;
   d5.today();
   fstream  fil2,fil3;

   fil2.open("hotel.dat",ios::binary | ios::in);
   fil3.open("temp.dat",ios::binary | ios::out);


     while(fil2.read ((char*)&user,sizeof (user)))
     { gotoxy(3,4);cout<<gd(d5,user.d);
     if(d5.m==(user.d).m)
       {if (abs(gd(d5,user.d))<=user.nods)
       fil3.write((char*)&user,sizeof (user));  }
       else if(d5.m!=(user.d).m)
    { if(abs(gd(d5,user.d))<=user.nods)
       fil3.write((char*)&user,sizeof (user));  }
     }

       getch();
   fil2.close();
   fil3.close();

   user.transferhoteldata();
}

float indian()
{
float s1=0;
int order;

int num1=0, num2=0, num3=0, num4=0, num5=0,num6=0,num7=0;
int num_customers;

double UnitPrice1= 150, UnitPrice2= 50,UnitPrice3= 65, UnitPrice4= 170, UnitPrice5= 110,UnitPrice6=70;
double AmountofSale1=0, AmountofSale2=0, AmountofSale3=0, AmountofSale4=0, AmountofSale5=0,AmountofSale6=0;

clrscr();
cout<<
		"\t\t_________________Indian________________\n\n"
	 <<"_____(1) Idly vada		    RS.150_____\n"
	 <<"_____(2) Dosa	                    RS.50_____\n"
	 <<"_____(3) Parotta                    RS.65(set)_____\n"
	 <<"_____(4) Meals		    RS.110_____\n"
	 <<"_____(5) Chappati	                    RS.70_____\n"
	 <<"_____(6) Puri	            RS.40_____\n";



cout<<"\n\nEnter Your Choice From The Given Menu :";
char kk;
do
{
cin>>order;
switch(order)
			{



				case 1:

		cout<<"How many IDLIS do you need ?:\n";
			       cin>>num1;

		AmountofSale1 = UnitPrice1 * num1;
		break;



case 2:
		cout<<"How many DOSAS do you like to order ?:\n";
					       cin>>num2;

		AmountofSale2= UnitPrice2 * num2;
		break;


		case 3:
		cout<<"How many PAROTTAS do you like to order ?:\n";
				  cin>>num3;

		AmountofSale3= UnitPrice3 * num3;
		break;



		case 4:
		cout<<"How many MEALS do you like to order ?:\n";
				cin>>num4;

		AmountofSale4= UnitPrice4 * num4;
		break;





		case 5:
		cout<<"How many CHAPPATIS do you like to order ?:\n";
				cin>>num5;

		AmountofSale5= UnitPrice5 * num5;
		break;
		case 6:
		cout<<"How many PURIS do you like to order ?:\n";
				cin>>num7;

		AmountofSale6= UnitPrice6 * num6;
		break;


		default: cout<<"Please choose from the given menu\n";
		 }
	       cout<<"\n\n\nWould you like to order anything else?:  ";
	       cin>>kk;

 }while(kk=='y'||kk=='Y');
clrscr();
cout<<"\n\nYou have ordered:\n\n";
gotoxy(8,22);
cout<<setw(10)<<"ITEM"<<setw(15)<<"QUANTITY"<<setw(15)<<"UNIT PRICE"<<setw(20)<<"AMOUNT OF SALE\n";
if(order==1)
{
gotoxy(8,23);
cout<<setw(10)<<"IDLY VADA"<<setw(10)<< num1 <<setw(15)<< UnitPrice1 <<setw(20) << AmountofSale1<<endl;
}
else if(order==2)
{
gotoxy(8,24);
cout<<setw(10)<<"DOSA"<<setw(14)<< num2 <<setw(15)<< UnitPrice2 <<setw(20) << AmountofSale2<<endl;
}
else if(order==3)
{
gotoxy(8,25);
cout<<setw(10)<<"PAROTTA"<<setw(14)<< num3 <<setw(15)<< UnitPrice3 <<setw(20) << AmountofSale3<<endl;
}
else if(order==4)
{
gotoxy(12,26);
cout<<setw(13)<<"\tMEALS"<<setw(5)<< num4 <<setw(15)<< UnitPrice4 <<setw(20) << AmountofSale4<<endl;
}
else if(order==5)
{
gotoxy(8,27);
cout<<setw(10)<<"\tCHAPPATIS"<<setw(13)<< num5 <<setw(15)<< UnitPrice5 <<setw(20) << AmountofSale5<<endl;
}
else if(order==6)
{
gotoxy(8,28);
cout<<setw(10)<<"\tPURIS"<<setw(18)<< num6 <<setw(15)<< UnitPrice6 <<setw(20) << AmountofSale6<<endl;
}

s1=(UnitPrice1*num1)+(UnitPrice2*num2)+(UnitPrice3*num3)+(UnitPrice4*num4)+(UnitPrice5*num5)+(UnitPrice6*num6) ;
return s1;
}


float chinese()
{
float s2=0;
int order;

int num1=0, num2=0, num3=0, num4=0, num5=0,num6=0,num7=0;
int num_customers;

const double UnitPrice1= 250, UnitPrice2= 90,UnitPrice3= 95, UnitPrice4= 190, UnitPrice5= 150,UnitPrice6=99,UnitPrice7=140;
double AmountofSale1=0, AmountofSale2=0, AmountofSale3=0, AmountofSale4=0, AmountofSale5=0,AmountofSale6=0,AmountofSale7=0;

gotoxy(8,3);
cout<<
		"\t\t___________________Menu________________\n\n"
	 <<"\t_____(1) Sour Pork		    RS.250_____\n"
	 <<"\t_____(2) Duck	                    RS.90_____\n"
	 <<"\t_____(3) Ma Tofu                    RS.95(set)_____\n"
	 <<"\t_____(4)Gong Bao Chicken 	    RS.190_____\n"
	 <<"\t_____(5) Wontons	            RS.150_____\n"
	 <<"\t_____(6) Chow Mein	            RS.99_____\n"
	 <<"\t_____(7) Spring Roll                RS.140_____\n";


gotoxy(8,13);
cout<<"From the list of food, what would you like:\n";
char kk;
do
{
cin>>order;
switch(order)
			{

		case 0:
		break;

				case 1:

		 gotoxy(8,15);
		cout<<"How many Sour Pork would you like to order:\n";
			       cin>>num1;

		AmountofSale1 = UnitPrice1 * num1;
		break;




				case 2:
				gotoxy(8,15);
		cout<<"How many Duck would you like to order:\n";
					       cin>>num2;

		AmountofSale2= UnitPrice2 * num2;
		break;


		case 3:
		gotoxy(8,15);
		cout<<"How many Ma Tofu would you like to order:\n";
				  cin>>num3;

		AmountofSale3= UnitPrice3 * num3;
		break;



		case 4:
		gotoxy(8,15);
		cout<<"How many Gong Bao Chicken would you like to order:\n";
				cin>>num4;

		AmountofSale4= UnitPrice4 * num4;
		break;



		case 5:
		gotoxy(8,15);
		cout<<"How many would Wontons you like to order:\n";
				cin>>num5;

		AmountofSale5= UnitPrice5 * num5;
		break;

		case 6:
		gotoxy(8,15);
		cout<<"How many would Chow Mein you like to order:\n";
				cin>>num6;

		AmountofSale6= UnitPrice6 * num6;
		break;
		case 7:
		gotoxy(8,15);
		cout<<"How many would Spring Roll you like to order:\n";
				cin>>num7;

		AmountofSale7= UnitPrice7 * num7;
		break;


		default:
		gotoxy(8,15);cout<<"Please choose a valid item from our list\n";
		 }
		 gotoxy(9,17);
	       cout<<"\nDO YOU WANT TO BUY ANYTHING ELSE:  ";
	       cin>>kk;

 }while(kk=='y'||kk=='Y');



cout<<"\n\nYou have ordered:\n\n";

gotoxy(8,22);
cout<<setw(10)<<"ITEM"<<setw(15)<<"QUANTITY"<<setw(15)<<"UNIT PRICE"<<setw(20)<<"AMOUNT OF SALE\n";
if(order==1)
{
gotoxy(8,23);
cout<<setw(10)<<"Sour Pork"<<setw(10)<< num1 <<setw(15)<< UnitPrice1 <<setw(20) << AmountofSale1<<endl;
}
if(order==2)
{
gotoxy(8,24);
cout<<setw(10)<<"Duck"<<setw(14)<< num2 <<setw(15)<< UnitPrice2 <<setw(20) << AmountofSale2<<endl;
}
if(order==3)
{
gotoxy(8,25);
cout<<setw(10)<<"Ma Tofu"<<setw(14)<< num3 <<setw(15)<< UnitPrice3 <<setw(20) << AmountofSale3<<endl;
}
if(order==4)
{
gotoxy(12,26);
cout<<setw(13)<<"\tGong Bao Chicken"<<setw(5)<< num4 <<setw(15)<< UnitPrice4 <<setw(20) << AmountofSale4<<endl;
}
if(order==5)
{
gotoxy(8,27);
cout<<setw(10)<<"\tWontons"<<setw(13)<< num5 <<setw(15)<< UnitPrice5 <<setw(20) << AmountofSale5<<endl;
}
if(order==6)
{
gotoxy(8,28);
cout<<setw(10)<<"\tChow Mein"<<setw(18)<< num6 <<setw(15)<< UnitPrice6 <<setw(20) << AmountofSale6<<endl;
}
if(order==7)
{
gotoxy(8,29);
cout<<setw(10)<<"\tSpring Roll"<<setw(10)<< num7 <<setw(15)<< UnitPrice7 <<setw(20) << AmountofSale7<<endl;
}

s2=(UnitPrice1*num1)+(UnitPrice2*num2)+(UnitPrice3*num3)+(UnitPrice4*num4)+(UnitPrice5*num5)+(UnitPrice6*num6)+(UnitPrice7*num7) ;
return s2;
}


float italian()
{
float s3=0;

int order;

int num1=0, num2=0, num3=0, num4=0, num5=0,num6=0,num7=0;
int num_customers;

const double UnitPrice1= 250, UnitPrice2= 150,UnitPrice3= 165, UnitPrice4= 270, UnitPrice5= 110,UnitPrice6=90,UnitPrice7=400;
double AmountofSale1=0, AmountofSale2=0, AmountofSale3=0, AmountofSale4=0, AmountofSale5=0,AmountofSale6=0,AmountofSale7=0;

gotoxy(8,3);
cout<<
		"\t\t___________________Menu________________\n\n"
	 <<"\t_____(1) PANZENELLA		    RS.250_____\n"
	 <<"\t_____(2) PASTA	                    RS.150_____\n"
	 <<"\t_____(3) FOCACCIA                   RS.165(set)_____\n"
	 <<"\t_____(4) BRUSCHETTA	            RS.270_____\n"
	 <<"\t_____(5) POMODORO	            RS.110_____\n"
	 <<"\t_____(6) RISOTTO	            RS.90_____\n"
	 <<"\t_____(7) MARGHERITA PIZZA	    RS.400_____\n";


gotoxy(8,13);
cout<<"From the list of food, what would you like:\n";
char kk;
do
{
cin>>order;
switch(order)
			{

		case 0:
		break;

				case 1:

		 gotoxy(8,15);
		cout<<"How many PANZENELLA would you like to order:\n";
			       cin>>num1;

		AmountofSale1 = UnitPrice1 * num1;
		break;




				case 2:
				gotoxy(8,15);
		cout<<"How many PASTA would you like to order:\n";
					       cin>>num2;

		AmountofSale2= UnitPrice2 * num2;
		break;


		case 3:
		gotoxy(8,15);
		cout<<"How many FOCACCIA would you like to order:\n";
				  cin>>num3;

		AmountofSale3= UnitPrice3 * num3;
		break;



		case 4:
		gotoxy(8,15);
		cout<<"How many BRUSCHETTA would you like to order:\n";
				cin>>num4;

		AmountofSale4= UnitPrice4 * num4;
		break;



		case 5:
		gotoxy(8,15);
		cout<<"How many would POMODORO you like to order:\n";
				cin>>num5;

		AmountofSale5= UnitPrice5 * num5;
		break;

		case 6:
		gotoxy(8,15);
		cout<<"How many would RISOTTO you like to order:\n";
				cin>>num6;

		AmountofSale6= UnitPrice6 * num6;
		break;
		case 7:
		gotoxy(8,15);
		cout<<"How many would MARGHERITA PIZZA you like to order:\n";
				cin>>num7;

		AmountofSale7= UnitPrice7 * num7;
		break;


		default:
		gotoxy(8,15);cout<<"Please choose a valid item from our list\n";
		 }
		 gotoxy(9,17);
	       cout<<"\nDO YOU WANT TO BUY ANYTHING ELSE:  ";
	       cin>>kk;

 }while(kk=='y'||kk=='Y');



cout<<"\n\nYou have ordered:\n\n";
gotoxy(8,22);
cout<<setw(10)<<"ITEM"<<setw(15)<<"QUANTITY"<<setw(15)<<"UNIT PRICE"<<setw(20)<<"AMOUNT OF SALE\n";
if(order==1)
{
gotoxy(8,23);
cout<<setw(10)<<"PANZENELLA"<<setw(10)<< num1 <<setw(15)<< UnitPrice1 <<setw(20) << AmountofSale1<<endl;
}
else if(order==2)
{
gotoxy(8,24);
cout<<setw(10)<<"PASTA"<<setw(14)<< num2 <<setw(15)<< UnitPrice2 <<setw(20) << AmountofSale2<<endl;
}
else if(order==3)
{
gotoxy(8,25);
cout<<setw(10)<<"FOCACCIA"<<setw(14)<< num3 <<setw(15)<< UnitPrice3 <<setw(20) << AmountofSale3<<endl;
}
else if(order==4)
{
gotoxy(12,26);
cout<<setw(13)<<"\tBRUSCHETTA"<<setw(5)<< num4 <<setw(15)<< UnitPrice4 <<setw(20) << AmountofSale4<<endl;
}
else if(order==5)
{
gotoxy(8,27);
cout<<setw(10)<<"\tPOMODORO"<<setw(13)<< num5 <<setw(15)<< UnitPrice5 <<setw(20) << AmountofSale5<<endl;
}
else if(order==6)
{
gotoxy(8,28);
cout<<setw(10)<<"\tRISOTTO"<<setw(18)<< num6 <<setw(15)<< UnitPrice6 <<setw(20) << AmountofSale6<<endl;
}
else if(order==7)
{
gotoxy(8,29);
cout<<setw(10)<<"\tMARGHERTIA PIZZA"<<setw(10)<< num7 <<setw(15)<< UnitPrice7 <<setw(20) << AmountofSale7<<endl;
}

s3=(UnitPrice1*num1)+(UnitPrice2*num2)+(UnitPrice3*num3)+(UnitPrice4*num4)+(UnitPrice5*num5)+(UnitPrice6*num6)+(UnitPrice7*num7) ;
return s3;
}


float mexico()
{
float s4=0;

int order;

int num1=0, num2=0, num3=0, num4=0, num5=0,num6=0,num7=0;
int num_customers;

const double UnitPrice1= 350, UnitPrice2= 150,UnitPrice3= 265, UnitPrice4= 270, UnitPrice5= 210,UnitPrice6=190,UnitPrice7=300;
double AmountofSale1=0, AmountofSale2=0, AmountofSale3=0, AmountofSale4=0, AmountofSale5=0,AmountofSale6=0,AmountofSale7=0;

gotoxy(8,3);
cout<<
		"\t\t___________________Menu________________\n\n"
	 <<"\t_____(1) CHILAQUILES		    RS.350_____\n"
	 <<"\t_____(2) SALSA	                    RS.150_____\n"
	 <<"\t_____(3) TACOS                      RS.265(set)_____\n"
	 <<"\t_____(4) ENCHILADAS	            RS.270_____\n"
	 <<"\t_____(5) SKILLET                    RS.210_____\n"
	 <<"\t_____(6) TAMALE PIE	            RS.190_____\n"
	 <<"\t_____(7) CARNE ASADA	            RS.300_____\n";


gotoxy(8,13);
cout<<"From the list of food, what would you like:\n";
char kk;
do
{
cin>>order;
switch(order)
			{

		case 0:
		break;

				case 1:

		 gotoxy(8,15);
		cout<<"How many CHILAQUILES would you like to order:\n";
			       cin>>num1;

		AmountofSale1 = UnitPrice1 * num1;
		break;




				case 2:
				gotoxy(8,15);
		cout<<"How many SALSA would you like to order:\n";
					       cin>>num2;

		AmountofSale2= UnitPrice2 * num2;
		break;


		case 3:
		gotoxy(8,15);
		cout<<"How many TACOS would you like to order:\n";
				  cin>>num3;

		AmountofSale3= UnitPrice3 * num3;
		break;



		case 4:
		gotoxy(8,15);
		cout<<"How many ENCHILADAS would you like to order:\n";
				cin>>num4;

		AmountofSale4= UnitPrice4 * num4;
		break;



		case 5:
		gotoxy(8,15);
		cout<<"How many would SKILLET you like to order:\n";
				cin>>num5;

		AmountofSale5= UnitPrice5 * num5;
		break;

		case 6:
		gotoxy(8,15);
		cout<<"How many would TAMALE PIE you like to order:\n";
				cin>>num6;

		AmountofSale6= UnitPrice6 * num6;
		break;
		case 7:
		gotoxy(8,15);
		cout<<"How many would CARNE ASADA you like to order:\n";
				cin>>num7;

		AmountofSale7= UnitPrice7 * num7;
		break;


		default:
		gotoxy(8,15);cout<<"Please choose a valid item from our list\n";
		 }
		 gotoxy(9,17);
	       cout<<"\nDO YOU WANT TO BUY ANYTHING ELSE:  ";
	       cin>>kk;

 }while(kk=='y'||kk=='Y');



cout<<"\n\nYou have ordered:\n\n";
gotoxy(8,22);
cout<<setw(10)<<"ITEM"<<setw(15)<<"QUANTITY"<<setw(15)<<"UNIT PRICE"<<setw(20)<<"AMOUNT OF SALE\n";
if(order==1)
{
gotoxy(8,23);
cout<<setw(10)<<"CHILAQUILES"<<setw(10)<< num1 <<setw(15)<< UnitPrice1 <<setw(20) << AmountofSale1<<endl;
}
else if(order==2)
{
gotoxy(8,24);
cout<<setw(10)<<"SALSA"<<setw(14)<< num2 <<setw(15)<< UnitPrice2 <<setw(20) << AmountofSale2<<endl;
}
else if(order==3)
{
gotoxy(8,25);
cout<<setw(10)<<"TACOS"<<setw(14)<< num3 <<setw(15)<< UnitPrice3 <<setw(20) << AmountofSale3<<endl;
}
else if(order==4)
{
gotoxy(12,26);
cout<<setw(13)<<"\tENCHILADAS"<<setw(5)<< num4 <<setw(15)<< UnitPrice4 <<setw(20) << AmountofSale4<<endl;
}
else if(order==5)
{
gotoxy(8,27);
cout<<setw(10)<<"\tSKILLET"<<setw(13)<< num5 <<setw(15)<< UnitPrice5 <<setw(20) << AmountofSale5<<endl;
}
else if(order==6)
{
gotoxy(8,28);
cout<<setw(10)<<"\tTAMALE PIE"<<setw(18)<< num6 <<setw(15)<< UnitPrice6 <<setw(20) << AmountofSale6<<endl;
}
else if(order==7)
{
gotoxy(8,29);
cout<<setw(10)<<"\tCARNE ASADA"<<setw(10)<< num7 <<setw(15)<< UnitPrice7 <<setw(20) << AmountofSale7<<endl;
}

s4=(UnitPrice1*num1)+(UnitPrice2*num2)+(UnitPrice3*num3)+(UnitPrice4*num4)+(UnitPrice5*num5)+(UnitPrice6*num6)+(UnitPrice7*num7) ;
return s4;

}

void travelagency::select()       //error
{                        price2=0;
fstream f; char cname[20];
cout<<"\n\nIf existing customer ,please enter your name:";
gets(cname);
travelagency t;
 float tot=0;
 {  clrscr();
char cch;
do{
 clrscr();
 gotoxy(8,3);
 cout<<"MENU";
 gotoxy(8,4);
 cout<<"____";
 gotoxy(8,7);
 cout<<"1.INDIAN DISH";
 gotoxy(8,9);
 cout<<"2.CHINESE DISH";
 gotoxy(8,11);
 cout<<"3.ITALIAN DISH";
 gotoxy(8,13);
 cout<<"4.MEXICAN DISH ";
 gotoxy(8,15);
 cout<<"CHOOSE YOUR OPTION:";
 int n;
 cin>>n;
 if(n==1)
 {tot+=indian();
 cout<<tot;   }
 else if(n==2)
 tot+=chinese();
 else if(n==3)
 tot+=italian();
 else if(n==4)
 tot+=mexico();
getch();

cout<<"\n\n\n\n\n\n     Do you want to check out other cuisines?:";
cin>>cch;
}while(cch=='y'||cch=='Y');
getch();
}
edithoteldata(cname,tot);
getch();
}
void travelagency::edithoteldata(char *ename, float tot)
{
clrscr();
strupr(ename);

fstream fil5,fil6;
fil5.open("hotel.dat",ios::binary | ios::in) ;
fil6.open("temp1.dat",ios::binary | ios::out ) ;
int ede=0;
 while(fil5.read((char*)&user,sizeof(user)))
  {
   if (strcmpi(ename,user.name)==0)
   {
    user.price2+=tot;
    ede++;
   }
   fil6.write((char*)&user,sizeof (user));
  }
  if(ede==0)
  {
  gotoxy(25,17);cout<<"RECORD DOESNT EXIST!!!!";
  }
getch();
fil5.close();
fil6.close();
transferhoteldata1();                             //TO TRANSFER EDITED HOTEL RECORD
}


void travelagency::delhotelrec()
{
clrscr();

char dname[20];
 gotoxy(20,5);cout<<"Enter name to delete record for...";
 gotoxy(30,7);gets(dname);
 strupr(dname);

   fstream  fil2,fil3;
   int del=0;

   fil2.open("hotel.dat",ios::binary | ios::in);
   fil3.open("temp.dat",ios::binary | ios::out);

     while(fil2.read ((char*)&user,sizeof (user)))
     {
       if ((strcmp(user.name,dname))!=0)
       fil3.write((char*)&user,sizeof (user));
       else
       del++;
     }
       if(del!=0)
       cout<<endl<<"                         ...Deleted...";
       else
       cout<<endl<<"                       Record not found..";
       getch();
   fil2.close();
   fil3.close();
fstream oldfile,newfile;

oldfile.open("temp.dat",ios::binary | ios::in);
newfile.open("hotel.dat",ios::binary | ios::out);

  while(oldfile.read((char*)&user,sizeof(user)))
  newfile.write((char*)&user,sizeof (user));

oldfile.close();
newfile.close();

}


/**********************************************
FUNTION USED TO TRANSFER UNDELETED HOTEL RECORDS.
**********************************************/
void travelagency::transferhoteldata()
{

fstream oldfile,newfile;


oldfile.open("temp.dat",ios::binary | ios::in);
newfile.open("hotel.dat",ios::binary | ios::out);

  while(oldfile.read((char*)&user,sizeof(user)))
  newfile.write((char*)&user,sizeof (user));

oldfile.close();
newfile.close();
}


/**********************************************
FUNTION USED TO SEARCH FOR A HOTEL RECORD.
**********************************************/
void travelagency::searchhotrec()
{
clrscr();

char sname[20];
  gotoxy(20,5);cout<<"Enter Name to search for..";
  gotoxy(25,7);gets(sname);
  strupr(sname);

   fstream fil4;
   fil4.open("hotel.dat",ios::binary | ios::in);

   int srch=0;

     while(fil4.read((char*)&user,sizeof (user)))
     {
       if(strcmp(user.name,sname)==0)
       {
       srch++;
       user.showhotel();
       }
     }
       if(srch==0)
       cout<<"                         No Record Exists";
    fil4.close();
getch();
}
int  chkhot(char sname[20])
{
clrscr();


strcpy(sname,strupr(sname));

   fstream fil4;
   fil4.open("hotel.dat",ios::binary | ios::in);

   int srch=0;
   long position;

     while(fil4.read((char*)&user,sizeof (user)))
     {
       if(strcmp(user.gname(),sname)==0)
       {
       srch++;
      position=fil4.tellp();
      break;
       }
     }
       if(srch==0)
       cout<<"                         No Record Exists";
    fil4.close();
	  getch();
return position;
}


/**********************************************
FUNTION USED TO EDIT A  HOTEL RECORD.
**********************************************/
void travelagency::edithoteldata()
{
clrscr();
char ename[30];int ede=0;
gotoxy(20,5);cout<<"Enter Name to Edit Record for...";
gotoxy(25,7);gets(ename);
strupr(ename);

fstream fil5,fil6;
fil5.open("hotel.dat",ios::binary | ios::in) ;
fil6.open("temp1.dat",ios::binary | ios::out ) ;

 while(fil5.read((char*)&user,sizeof(user)))
  {
   if (strcmp (ename,user.name)!=0)
   {
   fil6.write((char*)&user,sizeof (user));
   ede++;
  }      }
  if(ede==0)
  {
  gotoxy(25,17);cout<<"RECORD DOESNT EXIST!!!!";
  }
  user.resho();
  fil6.write((char*)&user,sizeof(user));
getch();
fil5.close();
fil6.close();
transferhoteldata1();                             //TO TRANSFER EDITED HOTEL RECORD
}


/**********************************************
FUNTION USED TO TRANSFER EDITED HOTEL RECORDS.
**********************************************/
void travelagency::transferhoteldata1()
{
fstream oldfile2,newfile2;

oldfile2.open("temp1.dat",ios::binary | ios::in);
newfile2.open("hotel.dat",ios::binary | ios::out);

  while(oldfile2.read((char*)&user,sizeof(user)))
  newfile2.write((char*)&user,sizeof (user));

oldfile2.close();
newfile2.close();
}
//
void open()
{ char str[10];int k=0;
clrscr();
	pass:;
	cout<<"\n\n\tPLEASE BE CAREFUL ENTER THE PASSWORD IN SMALL LETTERS\n";
	cout<<"\n\t\tPASSWORD DOES NOT CONTAINS ANY NUMBER\n\n\n";
	cout<<"\n\n\t\t\tEnter your Password\t";
	str[0]=getch();
	cout<<"*";
	str[1]=getch();
	cout<<"*";
	str[2]=getch();
	cout<<"*";
	str[3]=getch();
	cout<<"*";
	str[4]=getch();
	cout<<"*";
	str[5]=getch();
	cout<<"*";
	str[6]=getch();
	cout<<"*";
	str[7]='\0';
	cout<<"*";
	if(strcmp(str,"qwerty8")==0)
	{
	cout<<"\n\n\n\t\tPLEASE WAIT WHILE LOADING THE PROJECT";
	delay(150);
	cout<<".";
	delay(150);
	cout<<".";
	delay(150);
	cout<<".";
	delay(150);
	cout<<".";
	delay(150);
	cout<<".";
	delay(150);
	cout<<".";
	delay(150);
	cout<<".";
	delay(150);
	cout<<".";
	delay(150);
	cout<<".";
	delay(150);
	cout<<".";
	delay(200);
	}
	else
	{
	cout<<"\n\n\t\t\t$$$$$$ Ooop's wrong password $$$$$$\n";
	cout<<"\n\n\t\t\t%%%%%% Please re-enter the password%%%%%%\n";
	getch();
	k++;
	//getch();
	if(k==3)
	{
	cout<<"\nBye";
	getch();
	exit(0);
	}
	goto pass;
	}
       } //
/*_____________________________________________________________________________________________************************************************************************************/

				/**********************************************
						      MAIN FUNTION
					  USED TO CALL OTHER FUNTIONS
				**********************************************/

/*_____________________________________________________________________________________________************************************************************************************/


void main()
{
clrscr();

datedel();
clrscr();
cout.setf(ios::fixed,ios::floatfield);
cout.setf(ios::showpoint);
startup();                       //FUNTION TO DISPLAY INTRODUCTION SCREEN
int opt;
do
{
opt=opening1();                  //FUNTION CALL TO DISPLAY MENU
 switch(opt)
 {
 case 1:                         //FUNTION CALL TO RESERVE HOTEL
	makehofile();i++;
	break;
 case 5:		  //FUNTION CALL TO RESERVE HOTEL
	makehofile();i++;
	break;
 case 6:clrscr();
	travelagency x;
       x.viewhorec(); break;
 case 3:clrscr();
	x.select();
	break;
 case 7: clrscr();
	x.select();
	break;
 case 4: exit(0);break;
 case 8: exit(0);break;
 case 2:travelagency v;
	 v.searchhotrec();

 }
}while(opt<=7);
}


/**********************************************
FUNTION USED TO MAKE TRANSPORT RECORD.
**********************************************


/**********************************************
FUNTION USED TO MAKE HOTEL RECORD.
**********************************************/
void makehofile()
{
       fstream fil;
       fil.open("hotel.dat",ios::binary | ios::out |ios::app );
       user1[i].toggle=1;
       user1[i].resho();
       fil.write((char*)&user1[i],sizeof (user1[i]));
       fil.close();
}

/*

/**********************************************
FUNTION USED TO DISPLAY INTRODUCTION SCREEN
**********************************************/
void startup()
{
 int a;
 for(a=50;a>30;a--)
  {
  clrscr();
  textcolor(GREEN);
  textbackground(WHITE);
  gotoxy(25,10);cout<<"Welcome to the TRAVEL AGENCY";
  gotoxy(a,12);cout<<" V.A.T Prsents .... ";
  delay(50);
  }
 for(a=42;a<52;a++)
  {
  gotoxy(27,18);cout<<"Please Wait";
  gotoxy(a,18);cout<<".";
  delay(400);
  }
clrscr();
textcolor(GREEN );
for(int j=0;j<10;j++)
{
clrscr();
gotoxy(j,6); cout<<"        ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ";
gotoxy(j,7); cout<<"            ÜÜÜÜÜÜÜ ÜÜÜÜÜÜ ÜÜÜÜÜÜ";
gotoxy(j,8); cout<<"               Û    Û    Û Û    Û";
gotoxy(j,9); cout<<"               Û    ÛÜÜÜÛ  ÛÜÜÜÜÛ";
gotoxy(j,10);cout<<"               Û    Û Û    Û    Û";
gotoxy(j,11);cout<<"               Û    Û  ÛÛ  Û    Û";

gotoxy(51-j,6); cout<<"ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ \n\r";
gotoxy(51-j,7); cout<<" Ü    Ü ÜÜÜÜÜÜ Ü   \n\r";
gotoxy(51-j,8); cout<<" Û    Û Û      Û    \n\r";
gotoxy(51-j,9); cout<<" Û    Û ÛÜÜÜ   Û    \n\r";
gotoxy(51-j,10);cout<<"  Û  Û  Û      Û    \n\r";
gotoxy(51-j,11);cout<<"   ÛÛ   ÛÛÛÛÛÛ ÛÛÛÛ \n\r\n\n";

gotoxy(j,12);cout<<"                          ÜÜÜÜÜÜÜ Ü    Ü";
gotoxy(j,13);cout<<"                             Û    ÛÛ   Û";
gotoxy(j,14);cout<<"                             Û    Û Û  Û";
gotoxy(j,15);cout<<"                             Û    Û  Û Û";
gotoxy(j,16);cout<<"                          ÜÜÜÛÜÜÜ Û   ÛÛ";
gotoxy(j,17);cout<<"                     ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ";

gotoxy(58-j,12);cout<<" ÜÜÜÜÜÜ ÜÜÜÜÜÜÜ ÜÜÜÜÜÜ \n\r";
gotoxy(58-j,13);cout<<" Û    Û    Û    Û    Û \n\r";
gotoxy(58-j,14);cout<<" Û    Û    Û    ÛÜÜÜÜÛ \n\r";
gotoxy(58-j,15);cout<<" Û    Û    Û    Û    Û \n\r";
gotoxy(58-j,16);cout<<" ÛÜÜÜÜÛ ÜÜÜÛÜÜÜ Û    Û \n\r";
gotoxy(58-j,17);cout<<"ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ \n\r";

delay(80);
}
gotoxy(25,25);
cout<<"press any key to continue...";
getch();
}


/**********************************************
FUNTION USED TO DISPLAY MENU.
**********************************************/
int admin();
int opening1()
{
int pass,fl;
fl=admin();
if(fl==1)
{clrscr();
 for(int f=0;f<6;f++)
 {
 clrscr();
  textcolor(RED);
  textbackground(WHITE);
  gotoxy(10,f);cout<<"WELLCOME!!!!!!......"
		     "What would you like us to do for you";
  gotoxy(15,f+7);cout<<"1: Reserve Accomodation";
  gotoxy(15,f+9);cout<<"2: View Existing Bookings";
  gotoxy(15,f+11);cout<<"3: Restaurant";
  gotoxy(15,f+13);cout<<"4: Exit";
  gotoxy(13,f+16);cout<<"Enter (1,2,3 or 4)....? ";
  delay(100);
 }
 for(f=1;f<13;f++)
 {
  gotoxy(3,f);cout<<"@";gotoxy(80,f);cout<<"@";
  gotoxy(3,25-f);cout<<"@";gotoxy(80,25-f);cout<<"@";
  delay(50);
 }
gotoxy(40,19);

cin>>pass;
return(pass+4);
}
 else if(fl==0)
{clrscr();
 for(int f=0;f<6;f++)
 {

clrscr();
  textcolor(RED);
  textbackground(WHITE);
  gotoxy(10,f);cout<<"WELLCOME!!!!!!......"
		     "What would you like us to do for you";
  gotoxy(15,f+7);cout<<"1: Reserve Accomodation";
  gotoxy(15,f+9);cout<<"2: View your Bookings";
  gotoxy(15,f+11);cout<<"3: Restaurant";
  gotoxy(15,f+13);cout<<"4: Exit";
  gotoxy(13,f+16);cout<<"Enter (1,2,3 or 4)....? ";
  delay(100);
 }
 for(f=1;f<13;f++)
 {
  gotoxy(3,f);cout<<"@";gotoxy(80,f);cout<<"@";
  gotoxy(3,25-f);cout<<"@";gotoxy(80,25-f);cout<<"@";
  delay(50);
 }
gotoxy(40,19);

cin>>pass;
return(pass);

}
}
void opening2()     //function to display menu with places
{
int opt2;
 gotoxy(10,22);cout<<"1: Reserve Accomodation";
 gotoxy(10,24);cout<<"4: Exit  ???.... ";
 cin>>opt2;
 if (opt2!=4)
 {
  switch(opt2)
  {
  case 1:makehofile();i++;
	 break;
  }
 }
}

int o;


/**********************************************
FUNTION USED TOASSIGN PRICE ACCORDING TO DESTINATION.
**********************************************/


void travelagency::assignprice()
{
clrscr();
textcolor(YELLOW);
       textbackground(BLUE);
int toasspri;
  gotoxy(20,2);cout<<"PLEASE CHOOSE YOUR DESTINATION..";
  gotoxy(5,5);cout<<"1:Kashmir or Jammu                        2:Chandigarh";
  gotoxy(5,7);cout<<"3:Amritsar                                4: Shimla";
  gotoxy(5,9);cout<<"5:Kerala                                  6: Chennai ";
  gotoxy(5,11);cout<<"7:Hyderabad                              8: Mumbai ";
  gotoxy(5,13);cout<<"9:Port blair                             10: Guwahati";
  gotoxy(5,23);cout<<"Enter (1-10) to Reserve ...";
  gotoxy(45,23);cin>>toasspri;
  o=toasspri;
switch(toasspri)
{
 case 1:strcpy(destination,"jammu");
	break;
 case 2: strcpy(destination,"chandigarh");
	break;
 case 3: strcpy(destination,"amritsar");
	break;
 case 4:strcpy(destination,"shimla");

	break;
 case 5: strcpy(destination,"trivandrum");
	break;
 case 6: strcpy(destination,"chennai");
	break;
 case 7: strcpy(destination,"hyderabad");
	break;
 case 8:strcpy(destination,"mumbai");
	break;
 case 9:strcpy(destination,"portblair");
	break;
 case 10:strcpy(destination,"guwahati");
	 break;
}
}
 int admin()
{
int x,k=0;  char str[20];
clrscr();
cout<<"\n\n\n\n\t\t\t1.ADMIN:";
cout<<"\n\n\n\n\n\t\t\t2.USER:";
cin>>x;
if(x==1)
{   clrscr();
	pass:;
	cout<<"\n\n\tPLEASE BE CAREFUL ENTER THE PASSWORD IN SMALL LETTERS\n";
	cout<<"\n\t\tPASSWORD DOES NOT CONTAIN ANY NUMBERS\n\n\n";
	cout<<"\n\n\t\t\tEnter your Password\t";
	str[0]=getch();
	cout<<"*";
	str[1]=getch();
	cout<<"*";
	str[2]=getch();
	cout<<"*";
	str[3]=getch();
	cout<<"*";
	str[4]=getch();
	cout<<"*";
	str[5]=getch();
	cout<<"*";
	str[6]=getch();
	cout<<"*";
	str[7]='\0';
	cout<<"*";
	if(strcmp(str,"qwerty8")==0)
	{return 1;
	 }
	else
	{
	cout<<"\n\n\t\t\t$$$$$$ Ooop's wrong password $$$$$$\n";
	cout<<"\n\n\t\t\t%%%%%% Please re-enter the password%%%%%%\n";
	getch();
	k++;
	if(k==3)
	{
	cout<<"\nExiting from the project!!!!! Bye\n";
	getch();
	return -1;
	}
	goto pass;
	}
	}
	else if(x==2)
	{   return 0;
	 }

}

