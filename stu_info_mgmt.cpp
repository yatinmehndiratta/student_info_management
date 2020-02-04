#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<conio.h>
using namespace std;
struct student
{
 char name[20];
 char reg[15];
 char course[10];
 float cgpa;
 char phone[10];
};
fstream file;
student obj;
//-------------------------------------------------start of class------------------------------------------------------
class studentrec
{
public:

void add()
{
 cout<<"\n Enter Name: ";
 cin>>obj.name;
 cout<<"\n Enter Registration Number: ";
 cin>>obj.reg;
 cout<<"\n Enter Course: ";
 cin>>obj.course;
 cout<<"\n Enter CGPA: ";
 cin>>obj.cgpa;
 cout<<"\n Enter Phone Number: ";
 cin>>obj.phone;
 if(strcmp(obj.course,"bca")==0 || strcmp(obj.course,"BCA")==0)
 {
     file.open("bca.txt",ios::app);
 }
 else if(strcmp(obj.course,"mca")==0 || strcmp(obj.course,"MCA")==0)
 {
     file.open("mca.txt",ios::app);
 }
 file.write((char*)&obj,sizeof(obj));
 file.close();
}
//-----------------------------------------------------------------------------------------------------
void show_all()
{
 system("cls");
 char filetoopen[10];
 cout<<"Which file you would like to open, BCA or MCA ? ";
 cin>>filetoopen;
 if(strcmp(filetoopen,"bca")==0 || strcmp(filetoopen,"BCA")==0)
 {
     file.open("bca.txt",ios::in);
 }
 else if(strcmp(filetoopen,"mca")==0 || strcmp(filetoopen,"MCA")==0)
 {
     file.open("mca.txt",ios::in);
 }
 file.read((char*)&obj,sizeof(obj));

 while (file.eof()==0)
 {
  cout<<"Name: "<<obj.name<<endl;
  cout<<"Registration Number: "<<obj.reg<<endl;
  cout<<"Course: "<<obj.course<<endl;
  cout<<"CGPA: "<<obj.cgpa<<endl;
  cout<<"Phone: "<<obj.phone<<endl<<endl;
  file.read((char*)&obj,sizeof(obj));
 }
 file.close();
}
//------------------------------------------------------------------------------------------------------
void search()
{      system("cls");

  char filetosearchin[10];
 cout<<"In which file would you like to Search in, BCA or MCA ? ";
 cin>>filetosearchin;
 if(strcmp(filetosearchin,"bca")==0 || strcmp(filetosearchin,"BCA")==0)
 {
     file.open("bca.txt",ios::in);
 }
 else if(strcmp(filetosearchin,"mca")==0 || strcmp(filetosearchin,"MCA")==0)
 {
     file.open("mca.txt",ios::in);
 }

 char regno[20];
 cout<<"\n Enter Registration Number: ";
 cin>>regno;
// file.open("bca.txt",ios::in);
 file.read((char*)&obj,sizeof(obj));

 while (file.eof()==0)
 {
  if (strcmp(obj.reg,regno)==0)
  {
   cout<<"\nName: "<<obj.name<<endl;
   cout<<"Registration Number: "<<obj.reg<<endl;
   cout<<"Course: "<<obj.course<<endl;
   cout<<"CGPA: "<<obj.cgpa<<endl;
   cout<<"Phone: "<<obj.phone<<endl;
  }
  file.read((char*)&obj,sizeof(obj));
 }
 file.close();
}
//-------------------------------------------------------------------------------------------------
void edit()
{
    system("cls");
 char regno[15];
 cout<<"Enter Registration Number: ";
 cin>>regno;

 char filetoeditin[10];
 cout<<"in which file you would like to edit record in, bca or mca ? "<<endl;
 cin>>filetoeditin;
 if(strcmp(filetoeditin,"bca")==0 || strcmp(filetoeditin,"BCA")==0)
 {
     file.open("bca.txt",ios::in|ios::out);
 }
 else if(strcmp(filetoeditin,"mca")==0 || strcmp(filetoeditin,"MCA")==0)
 {
     file.open("mca.txt",ios::in|ios::out);
 }

 //file.open("bca.txt",ios::in|ios::out);
 file.read((char*)&obj,sizeof(obj));
 while (file.eof()==0)
 {
  if (strcmp(obj.reg,regno)==0)
  {
   cout<<"Name: "<<obj.name<<endl;
   cout<<"Registration Number: "<<obj.reg<<endl;
   cout<<"Course: "<<obj.course<<endl;
   cout<<"CGPA: "<<obj.cgpa<<endl;
   cout<<"Phone: "<<obj.phone<<endl;
   cout<<"\nEnter New Phone Number: ";
   cin>>obj.phone;
   file.seekp(file.tellg()-sizeof(obj)); // move one record backward from current position
   file.write((char*)&obj,sizeof(obj));
   cout<<"\n\n------------------ File Updated ------------------\n\n";
   break;
  }
        file.read((char*)&obj,sizeof(obj));
 }
        file.close();
}
//--------------------------------------------------------------------------------------------------------
void deleterecord()
{
    char regnumber[50],another;
    ifstream fp;
    ofstream ft;
    system("cls");

    char filetodeletefrom[10];
 cout<<"in which file you would like to delete record from, bca or mca ? "<<endl;
 cin>>filetodeletefrom;
 if(strcmp(filetodeletefrom,"bca")==0 || strcmp(filetodeletefrom,"BCA")==0)
 {
     fp.open("bca.txt",ios::in);
     another = 'Y';
        while (another == 'Y'|| another == 'y')
        {
              cout << "\n Enter the registration number of the student to delete its record: ";
              cin >> regnumber;
              ft.open("temp.txt",ios::out);
              fp.seekg(0,ios::beg);
              while(fp.read((char*)&obj,sizeof(obj)))
                {
                    if (strcmp(obj.reg,regnumber) != 0)
                        ft.write((char*)&obj,sizeof(obj));
                }
                fp.close();
                ft.close();
                remove("bca.txt");
                rename("temp.txt","bca.txt");
                cout<<"\n\n---- Student with Registration Number " << regnumber <<" is Deleted Successfully ----\n\n";
                cout << "\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
        }
 }
 else if(strcmp(filetodeletefrom,"mca")==0 || strcmp(filetodeletefrom,"MCA")==0)
 {
     fp.open("mca.txt",ios::in);
     another = 'Y';
        while (another == 'Y'|| another == 'y')
        {
              cout << "\n Enter the registration no. of the student to delete his/her record: ";
              cin >> regnumber;
              ft.open("temp.txt",ios::out);
              fp.seekg(0,ios::beg);
              while(fp.read((char*)&obj,sizeof(obj)))
                {
                    if (strcmp(obj.reg,regnumber) != 0)
                        ft.write((char*)&obj,sizeof(obj));
                }
                fp.close();
                ft.close();
                remove("mca.txt");
                rename("temp.txt","mca.txt");
                cout<<"\n\n------------ Student with Registration Number " << regnumber <<" is Deleted Successfully ------------\n\n";
                cout << "\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
        }
 }

//    fp.open("bca.txt",ios::in); //opened the file in read mode from which data which we need is to be copied

}
};

//----------------------------------------------end of class-----------------------------------------

int main()
{

 int option;
 studentrec sturec;
 cout<<"\n\n\n                         *******************************                     ";
 cout<<"\n\n                            STUDENT MANAGEMENT SYSTEM                     \n\n";
 cout<<"                         *******************************                     ";
 cout<<"\n\n\n\n\n                           Project by Yatin Mehndiratta                        ";
 cout<<"\n\n\n\n\n\n\n                        Press Any Key to Enter the Project";
 getch();
 system("cls");

 while(1)
 {
  cout<<"\n 1. Insert Record";
  cout<<"\n 2. Display Records";
  cout<<"\n 3. Search Records";
  cout<<"\n 4. Edit Phone Number";
  cout<<"\n 5. Delete Record";
  cout<<"\n 6. Exit";
  cout<<"\n\n Enter a Choice (1-6) ";
  cin>>option;

  switch(option)
  {
   case 1:  sturec.add();
    cout<<"\n\n-------- Record Entered Successfully --------\n\n";
    break;
    case 2:  sturec.show_all();
    break;
    case 3:  sturec.search();
    break;
    case 4:  sturec.edit();
    break;
    case 5: sturec.deleterecord();
    break;
    case 6:  exit(0);
  }
 }
}

