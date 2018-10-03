// MOBILE SHOP BILLING PROJECT
//***************************************************************
// HEADER FILE USED IN PROJECT
//***************************************************************
#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<fstream.h>
//***************************************************************
// LOADING
//***************************************************************
void load()
{
for(int a=10;a<=39;a++)
{
delay(42);
gotoxy(a,22);
cout<<" .";
}
for(int b=10;b<=37;b++)
{
delay(32);
gotoxy(b,22);
cout<<" .";
}
for(int c=10;c<=35;c++)
{
delay(22);
gotoxy(c,22);
cout<<" .";
}
for(int d=10;d<=33;d++)
{
delay(12);
gotoxy(d,22);
cout<<" .";
}
for(int e=10;e<=31;e++)
{
delay(2);
gotoxy(e,22);
cout<<" .";
}
delay(2);
for(int f=31;f<=41;f++)
{
delay(22);
gotoxy(f,22);
cout<<" . . . . .";
}
delay(2);
for(int g=50;g<=70;g++)
{
delay(42);
gotoxy(g,22);
cout<<" .";
}
gotoxy(70,22);
cout<<"  ";
for(int h=48;h<=70;h++)
{
delay(32);
gotoxy(h,22);
cout<<" .";
}
gotoxy(70,22);
cout<<"  ";
for(int i=46;i<=70;i++)
{
delay(22);
gotoxy(i,22);
cout<<" .";
}
gotoxy(70,22);
cout<<"  ";
for(int j=44;j<=70;j++)
{
delay(12);
gotoxy(j,22);
cout<<" .";
}
gotoxy(70,22);
cout<<"  ";
for(int k=42;k<=70;k++)
{
delay(2);
gotoxy(k,22);
cout<<" .";
}
gotoxy(70,22);
cout<<"  ";
}
//***************************************************************
// CLASS USED IN PROJECT
//***************************************************************
class product
{
public:
int pno;
char name[50];
float price,qty;
void create_product()
{
cout<<"\nPlease enter the product number      :  ";
cin>>pno;
cout<<"\nPlease enter the name of the product :  ";
gets(name);
cout<<"\nPlease enter the MRP of the product  :  $ ";
cin>>price;
}
void show_product()
{
cout<<"\nProduct number      : "<<pno;
cout<<"\n\nName of the product : ";
puts(name);
cout<<"\nMRP of the product  : $ "<<price;
}
int retpno()
{return pno;}
float retprice()
{return price;}
char* retname()
{return name;}
}; //class ends here
 
//***************************************************************
// global declaration for stream object, object
//***************************************************************
fstream fp;
product pr;
//***************************************************************
// function to write in file
//***************************************************************
void write_product()
{
fp.open("Shop.dat",ios::out|ios::app);
load();
clrscr();
pr.create_product();
fp.write((char*)&pr,sizeof(product));
fp.close();
load();
gotoxy(1,18);
cout<<"\n\nThe product has been registered to the records successfully.";
getch();
}
//***************************************************************
// function to read all records from file
//***************************************************************
void display_all()
{
clrscr();
load();
clrscr();
cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
fp.open("Shop.dat",ios::in);
while(fp.read((char*)&pr,sizeof(product)))
{
pr.show_product();
cout<<"\n\n====================================\n";
getch();
}
fp.close();
getch();
}
//***************************************************************
// function to read specific record from file
//***************************************************************
void display_sp(int n)
{
int flag=0;
fp.open("Shop.dat",ios::in);
while(fp.read((char*)&pr,sizeof(product)))
{
if(pr.retpno()==n)
{
clrscr();
pr.show_product();
flag=1;
}
}
fp.close();
if(flag==0)
{
gotoxy(1,5);
cout<<"Record does not exist.";
}
getch();
}
//***************************************************************
// function to modify record of file
//***************************************************************
void modify_product()
{
int no,found=0;
clrscr();
cout<<"\n\n\tTo Modify :";
cout<<"\n\n\tPlease enter the product number : ";
cin>>no;
fp.open("Shop.dat",ios::in|ios::out);
while(fp.read((char*)&pr,sizeof(product)) && found==0)
{
if(pr.retpno()==no)
{
load();
gotoxy(1,5);
pr.show_product();
cout<<"\n\nPlease enter the modified details : "<<endl;
pr.create_product();
int pos=-1*sizeof(pr);
fp.seekp(pos,ios::cur);
fp.write((char*)&pr,sizeof(product));
load();
gotoxy(1,19);
cout<<"\n\n\t Product modified and records updated successfully.";
found=1;
}
}
fp.close();
if(found==0)
cout<<"\n\n Product not found.";
getch();
}
//***************************************************************
// function to delete record of file
//***************************************************************
void delete_product()
{
int no;
clrscr();
cout<<"\n\n\n\tDelete product :";
cout<<"\n\nPlease enter the product number of the product you want to delete : ";
cin>>no;
fp.open("Shop.dat",ios::in|ios::out);
fstream fp2;
fp2.open("Temp.dat",ios::out);
fp.seekg(0,ios::beg);
while(fp.read((char*)&pr,sizeof(product)))
{
if(pr.retpno()!=no)
{
fp2.write((char*)&pr,sizeof(product));
}
}
fp2.close();
fp.close();
remove("Shop.dat");
rename("Temp.dat","Shop.dat");
load();
gotoxy(1,18);
cout<<"\n\n\tProduct deleted and records updated successfully.";
getch();
}
//***************************************************************
// function to display all products price list
//***************************************************************
void menu()
{
clrscr();
fp.open("Shop.dat",ios::in);
if(!fp)
{
cout<<"ERROR!!! FILE COULD NOT BE EXECUTED\n\n\n Go to the Admin Menu to create File";
cout<<"\n\n\n Program is closing ....";
getch();
exit(0);
}
load();
clrscr();
gotoxy(33,1);
cout<<" PRODUCT MENU ";
gotoxy(1,2);
cout<<"--------------------------------------------------------------------------------";
gotoxy(1,3);
cout<<"S.NO.";
gotoxy(7,3);
cout<<"||";
gotoxy(10,3);
cout<<"P.NO.";
gotoxy(17,3);
cout<<"||";
gotoxy(20,3);
cout<<"PRODUCT NAME";
gotoxy(51,3);
cout<<"||";
gotoxy(56,3);
cout<<"MRP";
gotoxy(1,4);
cout<<"--------------------------------------------------------------------------------";
for(int z=1;z<=30;z++)
while(fp.read((char*)&pr,sizeof(product)))
{
gotoxy(1,z+4);
cout<<z<<".";
gotoxy(7,z+4);
cout<<"||";
gotoxy(10,z+4);
cout<<pr.retpno();
gotoxy(17,z+4);
cout<<"||";
gotoxy(20,z+4);
cout<<pr.retname();
gotoxy(51,z+4);
cout<<"||";
gotoxy(54,z+4);
cout<<"$";
gotoxy(56,z+4);
cout<<pr.retprice();
z++;
}
cout<<endl<<"--------------------------------------------------------------------------------";
fp.close();
}
 
void admin_menu();
//***************************************************************
// function to place order and generating bill for Products
//***************************************************************
void place_order()
{
int order_arr[50],quan[50],c=0;
float amt,total=0;
char ch='Y';
menu();
cout<<"\n============================";
cout<<"\n PLACE YOUR ORDER";
cout<<"\n============================\n";
do
{
cout<<"\n\nEnter the product number : ";
cin>>order_arr[c];
cout<<"\nQuantity in number : ";
cin>>quan[c];
c++;
cout<<"\nWant to add another product to the current bill? (y/n) ";
cin>>ch;
}
while(ch=='y' || ch=='Y');
cout<<"\n\nThank you for shopping at the iNvent. Please visit again.";
getch();
clrscr();
load();
clrscr();
gotoxy(32,1);
cout<<" RETAIL INVOICE ";
gotoxy(1,2);
cout<<"--------------------------------------------------------------------------------";
gotoxy(1,3);
cout<<"S.NO.";
gotoxy(7,3);
cout<<"||";
gotoxy(10,3);
cout<<"P.NO.";
gotoxy(18,3);
cout<<"||";
gotoxy(21,3);
cout<<"PRODUCT NAME";
gotoxy(50,3);
cout<<"||";
gotoxy(53,3);
cout<<"QTY";
gotoxy(57,3);
cout<<"||";
gotoxy(62,3);
cout<<"MRP";
gotoxy(69,3);
cout<<"||";
gotoxy(74,3);
cout<<"AMT";
gotoxy(1,4);
cout<<"--------------------------------------------------------------------------------";
for(int x=0;x<=c;x++)
{
fp.open("Shop.dat",ios::in);
fp.read((char*)&pr,sizeof(product));
for(int z1=1;z1<=30;z1++)
while(!fp.eof())
{
if(pr.retpno()==order_arr[x])
{
amt=pr.retprice()*quan[x];
gotoxy(1,z1+4);
cout<<z1<<".";
gotoxy(7,z1+4);
cout<<"||";
gotoxy(10,z1+4);
cout<<order_arr[x];
gotoxy(18,z1+4);
cout<<"||";
gotoxy(21,z1+4);
cout<<pr.retname();
gotoxy(50,z1+4);
cout<<"||";
gotoxy(53,z1+4);
cout<<quan[x];
gotoxy(57,z1+4);
cout<<"||";
gotoxy(60,z1+4);
cout<<"$";
gotoxy(62,z1+4);
cout<<pr.retprice();
gotoxy(69,z1+4);
cout<<"||";
gotoxy(72,z1+4);
cout<<"$";
gotoxy(74,z1+4);
cout<<amt;
total+=amt;
}
z1++;
fp.read((char*)&pr,sizeof(product));
}
fp.close();
}
cout<<"\n\n\t\t\t\t\tTOTAL = $ "<<total;
getch();
}
//***************************************************************
// INTRODUCTION FUNCTION
//***************************************************************
void intro()
{
clrscr();
cout<<endl<<endl<<endl;
cout<<"  ##  ##          ## ##            ## ########## ##          ## ##############"<<endl;
cout<<"      ####        ##  ##          ##  ##         ####        ##       ##      "<<endl;
cout<<"  ##  ##  ##      ##   ##        ##   ##         ##  ##      ##       ##      "<<endl;
cout<<"  ##  ##    ##    ##    ##      ##    ######     ##    ##    ##       ##      "<<endl;
cout<<"  ##  ##      ##  ##     ##    ##     ##         ##      ##  ##       ##      "<<endl;
cout<<"  ##  ##        ####      ##  ##      ##         ##        ####       ##      "<<endl;
cout<<"  ##  ##          ##       ####       ########## ##          ##       ##      "<<endl;
gotoxy(32,13);
cout<<"iNvent Apple Store";
gotoxy(33,15);
cout<<"BILLING  MACHINE";
gotoxy(1,17);
cout<<"Owners  : Nirbhay Sibal";
gotoxy(11,19);
cout<<"Gaurav Kalsi";
cout<<"\n\nSchool  : Guru Harkrishan Public School, Punjabi Bagh";
getch();
clrscr();
load();
clrscr();
}
//***************************************************************
// THE CLOSING (LEFT & RIGHT)
//***************************************************************
void leftst()
{
for(int k=7;k<=36;k++)
{
delay(50);
gotoxy(k,13);
cout<<" ##";
gotoxy(k-2,12);
cout<<" ##";
gotoxy(k-4,11);
cout<<" ##";
gotoxy(k-6,10);
cout<<" ##";
gotoxy(k-2,14);
cout<<" ##";
gotoxy(k-4,15);
cout<<" ##";
gotoxy(k-6,16);
cout<<" ##";
gotoxy(40,13);
}
}

void rightst()
{
for(int j=72;j>=43;j--)
{
delay(50);
gotoxy(j,13);
cout<<"## ";
gotoxy(j+2,12);
cout<<"## ";
gotoxy(j+4,11);
cout<<"## ";
gotoxy(j+6,10);
cout<<"## ";
gotoxy(j+2,14);
cout<<"## ";
gotoxy(j+4,15);
cout<<"## ";
gotoxy(j+6,16);
cout<<"## ";
gotoxy(40,13);
}
}
//***************************************************************
// THE ENTRY/EXIT MENU OF THE PROGRAM
//***************************************************************
void emenu()
{
load();
clrscr();
char ch;
do
{
clrscr();
gotoxy(33,4);
cout<<"================";
gotoxy(34,5);
cout<<" MAIN  MENU ";
gotoxy(33,6);
cout<<"================";
gotoxy(33,9);
cout<<"1. CUSTOMER";
gotoxy(33,11);
cout<<"2. ADMINISTRATOR";
gotoxy(33,13);
cout<<"3. EXIT";
gotoxy(33,16);
cout<<"================";
gotoxy(26,18);
cout<<"Please enter your choice (1-3) ";
ch=getche();
switch(ch)
{
case '1': clrscr();
	  place_order();
	  break;
case '2': clrscr();
	  load();
	  admin_menu();
	  break;
case '3': clrscr();
	  load();
	  clrscr();
	  gotoxy(35,13);
	  cout<<"Thank You!!!";
	  delay(2000);
	  clrscr();
	  gotoxy(40,12);
	  cout<<"##";
	  gotoxy(38,11);
	  cout<<"##";
	  gotoxy(42,11);
	  cout<<"##";
	  gotoxy(36,10);
	  cout<<"##";
	  gotoxy(44,10);
	  cout<<"##";
	  gotoxy(40,14);
	  cout<<"##";
	  gotoxy(38,15);
	  cout<<"##";
	  gotoxy(42,15);
	  cout<<"##";
	  gotoxy(36,16);
	  cout<<"##";
	  gotoxy(44,16);
	  cout<<"##";
	  gotoxy(72,13);
	  cout<<"## ";
	  gotoxy(74,12);
	  cout<<"## ";
	  gotoxy(76,11);
	  cout<<"## ";
	  gotoxy(78,10);
	  cout<<"## ";
	  gotoxy(74,14);
	  cout<<"## ";
	  gotoxy(76,15);
	  cout<<"## ";
	  gotoxy(78,16);
	  cout<<"## ";
	  gotoxy(7,13);
	  cout<<" ##";
	  gotoxy(5,12);
	  cout<<" ##";
	  gotoxy(3,11);
	  cout<<" ##";
	  gotoxy(1,10);
	  cout<<" ##";
	  gotoxy(5,14);
	  cout<<" ##";
	  gotoxy(3,15);
	  cout<<" ##";
	  gotoxy(1,16);
	  cout<<" ##";
	  gotoxy(40,13);
	  rightst();
	  leftst();
	  delay(500);
	  exit(0);
default : cout<<"\a";
}
}while(ch!='3');
}
//***************************************************************
// ADMINSTRATOR MENU FUNCTION
//***************************************************************
void admin_menu()
{
clrscr();
char ch2;
gotoxy(31,2);
cout<<"====================";
gotoxy(34,3);
cout<<" ADMIN MENU ";
gotoxy(31,4);
cout<<"====================";
gotoxy(31,6);
cout<<"1. REGISTER PRODUCT";
gotoxy(31,8);
cout<<"2. DISPLAY PRODUCTS";
gotoxy(31,10);
cout<<"3. QUERY ";
gotoxy(31,12);
cout<<"4. MODIFY PRODUCT";
gotoxy(31,14);
cout<<"5. DELETE PRODUCT";
gotoxy(31,16);
cout<<"6. VIEW PRODUCT MENU";
gotoxy(31,18);
cout<<"7. BACK TO MAIN MENU";
gotoxy(31,20);
cout<<"====================";
gotoxy(26,22);
cout<<"Please enter your choice (1-7) ";
ch2=getche();
switch(ch2)
{
case '1': clrscr();
	  write_product();
	  break;
case '2': display_all();
	  break;
case '3': clrscr();
	  load();
	  int num;
	  clrscr();
	  cout<<"\n\n\tPlease enter the product no. : ";
	  cin>>num;
	  load();
	  display_sp(num);
	  break;
case '4': modify_product();
	  break;
case '5': delete_product();
	  break;
case '6': menu();
	  getch();
	  break;
case '7': clrscr();
	  emenu();
	  break;
default : cout<<"\a";
	  admin_menu();
}
}

//***************************************************************
// THE OPENING (LEFT & RIGHT)
//***************************************************************
void left()
{
for(int x=37;x>=8;x--)
{
delay(50);
gotoxy(x,13);
cout<<"## ";
gotoxy(x-2,12);
cout<<"## ";
gotoxy(x-4,11);
cout<<"## ";
gotoxy(x-6,10);
cout<<"## ";
gotoxy(x-2,14);
cout<<"## ";
gotoxy(x-4,15);
cout<<"## ";
gotoxy(x-6,16);
cout<<"## ";
gotoxy(40,13);
}
}

void right()
{
for(int i=42;i<=71;i++)
{
delay(50);
gotoxy(i,13);
cout<<" ##";
gotoxy(i+2,12);
cout<<" ##";
gotoxy(i+4,11);
cout<<" ##";
gotoxy(i+6,10);
cout<<" ##";
gotoxy(i+2,14);
cout<<" ##";
gotoxy(i+4,15);
cout<<" ##";
gotoxy(i+6,16);
cout<<" ##";
gotoxy(40,13);
}
}

//***************************************************************
// THE MAIN FUNCTION OF PROGRAM
//***************************************************************
void main()
{
clrscr();
intro();
clrscr();
int c,o,d,e;
gotoxy(1,5);
cout<<"You are going to operate a program which is accessible for iNvent Staff only.";
cout<<"\n\nYou have to enter the accees code";
cout<<"\n\nPlease enter the access code : ";
gotoxy(26,12);
cout<<"||=====||=====||=====||=====||";
gotoxy(26,13);
cout<<"||     ||     ||     ||     ||";
gotoxy(26,14);
cout<<"||=====||=====||=====||=====||";
gotoxy(30,13);
c=getch();
cout<<"*\a";
gotoxy(37,13);
o=getch();
cout<<"*\a";
gotoxy(44,13);
d=getch();
cout<<"*\a";
gotoxy(51,13);
e=getch();
cout<<"*\a";
load();
if(c=='2' && o=='6' && d=='3' && e=='3')
{
gotoxy(35,15);
cout<<"Code matched\a\a";
delay(2000);
clrscr();
gotoxy(40,12);
cout<<"##";
gotoxy(38,11);
cout<<"##";
gotoxy(42,11);
cout<<"##";
gotoxy(36,10);
cout<<"##";
gotoxy(44,10);
cout<<"##";
gotoxy(40,14);
cout<<"##";
gotoxy(38,15);
cout<<"##";
gotoxy(42,15);
cout<<"##";
gotoxy(36,16);
cout<<"##";
gotoxy(44,16);
cout<<"##";
gotoxy(42,13);
cout<<" ##";
gotoxy(44,12);
cout<<" ##";
gotoxy(46,11);
cout<<" ##";
gotoxy(48,10);
cout<<" ##";
gotoxy(44,14);
cout<<" ##";
gotoxy(46,15);
cout<<" ##";
gotoxy(48,16);
cout<<" ##";
gotoxy(37,13);
cout<<"## ";
gotoxy(35,12);
cout<<"## ";
gotoxy(33,11);
cout<<"## ";
gotoxy(31,10);
cout<<"## ";
gotoxy(35,14);
cout<<"## ";
gotoxy(33,15);
cout<<"## ";
gotoxy(31,16);
cout<<"## ";
gotoxy(40,13);
delay(1000);
left();
right();
emenu();
}
else
{
gotoxy(35,15);
cout<<"Invalid code\a\a";
delay(2000);
clrscr();
gotoxy(1,12);
cout<<"Unauthorised entry!!!";
gotoxy(1,14);
cout<<"The program will shut down itself automatically in ";
gotoxy(52,14);
cout<<"3 seconds";
delay(1000);
gotoxy(52,14);
cout<<"2 seconds";
delay(1000);
gotoxy(52,14);
cout<<"1 second ";
gotoxy(60,14);
delay(1000);
void exit();
}

}
//***************************************************************
// END OF PROJECT
//***************************************************************

