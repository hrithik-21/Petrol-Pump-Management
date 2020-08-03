#include<iostream>
#include<conio.h>
#include<fstream>
#include<process.h>
#include<stdio.h>
#include<string>
using namespace std;
class petroleum
{
 public:
 float qty;
 float price;
  void show()
   {
     std::cout<<"\n Quantity Of Petrol(In Litre) -:";
     std::cout<<qty;
     std::cout<<"\n Price-:";
     std::cout<<price;
   }
  void insert()
   {
     std::cout<<"\n Enter The Quantity Of Petrol(In Litre)-:";
     cin>>qty;
     std::cout<<"\n Price-:";
     cin>>price;
   }
   void dinsert()
   {
     std::cout<<"\n Enter The Quantity Of Diesel(In Litre)-:";
     cin>>qty;
     std::cout<<"\n Price-:";
     cin>>price;
   }
   void dshow()
   {
     std::cout<<"\n Quantity Of Diesel(In Litre) Left-:";
     std::cout<<qty;
     std::cout<<"\n Price-:";
     std::cout<<price;
   }
}pe;
char ch='y';
float rate;
float total;
float money;
fstream fin;
fstream fout;
fstream dfout;
fstream dfin;
int c;
void home();
void dstock()
{
 {
    dfin.open("diesel.dat",ios::out|ios::binary);
    pe.dinsert();
    dfin.write((char*)&pe,sizeof(pe));
  }
 dfin.close();
}
void stock()
{
  {
    fin.open("petrol.dat",ios::out|ios::binary);
    pe.insert();
    fin.write((char*)&pe,sizeof(pe));
  }
 fin.close();
}
void sell()
{
 fin.open("petrol.dat",ios::in|ios::binary);
 fout.open("temppetrol.dat",ios::out|ios::binary);
 std::cout<<"\n Enter Money-:";
 cin>>money;
 fin.read((char*)&pe,sizeof(pe));
  while(fin)
   {
     total=money/pe.price;
     std::cout<<"\n Petrol Sold(In Litre)-:"<<total;
     std::cout<<endl;
     std::cout<<endl;
     pe.qty=pe.qty-total;
     fout.write((char*)&pe,sizeof(pe));
     fin.read((char*)&pe,sizeof(pe));
   }
   fin.close();
   fout.close();
   {
    fin.open("petrol.dat",ios::out|ios::binary);
    fout.open("temppetrol.dat",ios::in|ios::binary);
    fout.read((char*)&pe,sizeof(pe));
     while(fout)
      {
	fin.write((char*)&pe,sizeof(pe));
	fout.read((char*)&pe,sizeof(pe));
      }
   }
   fin.close();
   fout.close();
   fin.open("petrol.dat",ios::in|ios::binary);
   fin.read((char*)&pe,sizeof(pe));
    while(fin)
     {
      std::cout<<"\n Litre Left After Selling-:";
      pe.show();
      fin.read((char*)&pe,sizeof(pe));
     }
   fin.close();


}
void dsell()
{
 dfin.open("diesel.dat",ios::in|ios::binary);
 dfout.open("tempdiesel.dat",ios::out|ios::binary);
 std::cout<<"\n Enter Money-:";
 cin>>money;
 dfin.read((char*)&pe,sizeof(pe));
  while(dfin)
   {
     total=money/pe.price;
     std::cout<<"\n Petrol Sold(In Litre)-:"<<total;
     std::cout<<endl;
     std::cout<<endl;
     pe.qty=pe.qty-total;
     dfout.write((char*)&pe,sizeof(pe));
     dfin.read((char*)&pe,sizeof(pe));
   }
   dfin.close();
   dfout.close();
   {
    dfin.open("diesel.dat",ios::out|ios::binary);
    dfout.open("tempdiesel.dat",ios::in|ios::binary);
    dfout.read((char*)&pe,sizeof(pe));
     while(dfout)
      {
	dfin.write((char*)&pe,sizeof(pe));
	dfout.read((char*)&pe,sizeof(pe));
      }
   }
   dfin.close();
   dfout.close();
   dfin.open("diesel.dat",ios::in|ios::binary);
   dfin.read((char*)&pe,sizeof(pe));
    while(dfin)
     {
      std::cout<<"\n Litre Left After Selling-:";
      pe.dshow();
      dfin.read((char*)&pe,sizeof(pe));
     }
   dfin.close();
}
void home()
{
 system("CLS");
std::cout<<"\t \t \t   ********************** \t \t"<<endl;
std::cout<<"\t \t \t  * BHARAT PETROLUEM INC. * \t \t";
std::cout<<"\n ------------------------------------------------------------------------------";
std::cout<<"\n WELCOME to the services of BHARAT PERTROLEUM INC. !! Here one can easily \n interact  with the people's good and services.";
std::cout<<"\n ";
std::cout<<"\n Here are some features given below -> "<<endl;
std::cout<<"\t \t      ________________________________ "<<endl;
std::cout<<"\t \t     I    * BHARAT PETROLEUM INC. *   I"<<endl;
std::cout<<"\t \t     I ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~I"<<endl;
std::cout<<"\t \t     I                                I"<<endl;
std::cout<<"\t \t     I  1) INFORMATION about BPI      I"<<endl;
std::cout<<"\t \t     I                                I"<<endl;
std::cout<<"\t \t     I  2) Add petrol In Your Stock   I"<<endl;
std::cout<<"\t \t     I  3) Sell petrol                I"<<endl;
std::cout<<"\t \t     I  4) Change In Rate (petrol)    I"<<endl;
std::cout<<"\t \t     I                                I"<<endl;
std::cout<<"\t \t     I  5) Add diesel In Your Stock   I"<<endl;
std::cout<<"\t \t     I  6) Sell diesel                I"<<endl;
std::cout<<"\t \t     I  7) Change In Rate (diesel)    I"<<endl;
std::cout<<"\t \t     I                                I"<<endl;
std::cout<<"\t \t     I  8) Exit                       I"<<endl;
std::cout<<"\t \t     I________________________________I"<<endl;
std::cout<<"\n ";
std::cout<<"\n ";
cin>>c;
 switch(c)
  {
  case 1:

   system("CLS");

std::cout<<"\t       ______________________________________________ "<<endl;
std::cout<<"\t      I              * BHARAT PETROLEUM INC. *       I"<<endl;
std::cout<<"\t      I ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~I"<<endl;
std::cout<<"\t      I                                              I"<<endl;
std::cout<<"\t      I  1) INFORMATION about BHARAT PETROLEUM Inc.  I"<<endl;
std::cout<<"\t      I     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  I"<<endl;
std::cout<<"\t      I This Petroleum Station is under the guidance I"<<endl;
std::cout<<"\t      I of the INDIAN GOVERNMENT and follows all the I"<<endl;
std::cout<<"\t      I rules and regulations implied by the govt.of I"<<endl;
std::cout<<"\t      I INDIA. This petrol station has been stablis- I"<<endl;
std::cout<<"\t      I hed in 1989 with the help of BHARAT PETRO&CO I"<<endl;
std::cout<<"\t      I who provided us with the licence and legal   I"<<endl;
std::cout<<"\t      I auhtorities. We whole HEARTEDLY welcome all  I"<<endl;
std::cout<<"\t      I costumers and buyers for showing interest &  I"<<endl;
std::cout<<"\t      I having faith, trust on us.We respect that &  I"<<endl;
std::cout<<"\t      I keep on improving our services for customer  I"<<endl;
std::cout<<"\t      I satisfaction.  :)                            I"<<endl;
std::cout<<"\t      I______________________________________________I"<<endl;

std::cout<<"\n Enter H For Home Screen Or E For Exit-:";
	   cin>>ch;
	   if(ch=='h')
	    {
	     home();
	    }
	   else
	    {
	     exit(0);
	    }
break;


   case 2: system("CLS");
	   stock();
	   std::cout<<"\n Enter H For Home Screen Or E For Exit-:";
	   cin>>ch;
	   if(ch=='h')
	    {
	     home();
	    }
	   else
	    {
	     exit(0);
	    }
	   break;
   case 3: system("CLS");
	   sell();
	   std::cout<<"\n Enter H For Home Screen Or E For Exit-:";
	   cin>>ch;
	   if(ch=='h')
	    {
	     home();
	    }
	   else
	    {
	     exit(0);
	    }
	   break;
   case 4: system("CLS");
	   fin.open("petrol.dat",ios::in|ios::binary);
	   fout.open("temppetrol.dat",ios::out|ios::binary);
	   fin.read((char*)&pe,sizeof(pe));
	    while(fin)
	       {
		    std::cout<<"\n Enter New Rate-:";
		    cin>>rate;
		    pe.price=rate;
		    fout.write((char*)&pe,sizeof(pe));
		    fin.read((char*)&pe,sizeof(pe));
	       }
   fin.close();
   fout.close();
   {
    fin.open("petrol.dat",ios::out|ios::binary);
    fout.open("temppetrol.dat",ios::in|ios::binary);
    fout.read((char*)&pe,sizeof(pe));
     while(fout)
      {
	fin.write((char*)&pe,sizeof(pe));
	fout.read((char*)&pe,sizeof(pe));
      }
   }
   fin.close();
   fout.close();
   fin.open("petrol.dat",ios::in|ios::binary);
   fin.read((char*)&pe,sizeof(pe));
    while(fin)
     {
      std::cout<<"\n Now Records After Modifying-:";
      pe.show();
      fin.read((char*)&pe,sizeof(pe));
     }
   fin.close();
	    std::cout<<"\n Enter H For Home Screen Or E For Exit-:";
	   cin>>ch;
	   if(ch=='h')
	    {
	     home();
	    }
	   else
	    {
	     exit(0);
	    }
	   break;
   case 5: system("CLS");
	   dstock();
	   std::cout<<"\n Enter H For Home Screen Or E For Exit-:";
	   cin>>ch;
	   if(ch=='h')
	    {
	     home();
	    }
	   else
	    {
	     exit(0);
	    }
	   break;
   case 6: system("CLS");
	   dsell();
	   std::cout<<"\n Enter H For Home Screen Or E For Exit-:";
	   cin>>ch;
	   if(ch=='h')
	    {
	     home();
	    }
	   else
	    {
	     exit(0);
	    }
	   break;
   case 7: system("CLS");

	   dfin.open("diesel.dat",ios::in|ios::binary);
	   dfout.open("tempdiesel.dat",ios::out|ios::binary);
	   dfin.read((char*)&pe,sizeof(pe));
	    while(dfin)
	       {
		    std::cout<<"\n Enter New Rate-:";
		    cin>>rate;
		    pe.price=rate;
		    dfout.write((char*)&pe,sizeof(pe));
		    dfin.read((char*)&pe,sizeof(pe));
	       }
   dfin.close();
   dfout.close();
   {
    dfin.open("diesel.dat",ios::out|ios::binary);
    dfout.open("tempdiesel.dat",ios::in|ios::binary);
    dfout.read((char*)&pe,sizeof(pe));
     while(dfout)
      {
	dfin.write((char*)&pe,sizeof(pe));
	dfout.read((char*)&pe,sizeof(pe));
      }
   }
   dfin.close();
   dfout.close();
   dfin.open("diesel.dat",ios::in|ios::binary);
   dfin.read((char*)&pe,sizeof(pe));
    while(dfin)
     {
      std::cout<<"\n Now Records After Modifying-:";
      pe.dshow();
      dfin.read((char*)&pe,sizeof(pe));
     }
   dfin.close();
   std::cout<<"\n Enter H For Home Screen Or E For Exit-:";
	   cin>>ch;
	   if(ch=='h')
	    {
	     home();
	    }
	   else
	    {
	     exit(0);
	    }
	   break;
   case 8: system("CLS");
	   exit(0);
	   break;
   default:std::cout<<"\n Invalid Choice";
  }
}
int main()
{
 system("CLS");
 home();
 system("pause");
}
