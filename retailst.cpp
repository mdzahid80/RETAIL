#include <iostream> 
#include <fstream> 

using namespace std;  

class shopping
{
private:
    int model;
    float price;
    float disc;
    string prod_name;

    public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void list();
    void receipt();
};

void shopping :: menu()
{
  int choice;
  string email;
  string password;

  cout<<"\t\t\t\t________________\n";
  cout<<"\t\t\t\t________________\n";
  cout<<"\t\t\t\t________________\n";
  cout<<"\t\t\t\tSUPERMARKET MENU\n";
  cout<<"\t\t\t\t________________\n";
  cout<<"\t\t\t\t________________\n";
  cout<<"\t\t\t\t________________\n";
   cout<<"\t\t\t\t               \n";
  cout<<"\t\t\t\t|1) Administrator\n";
   cout<<"\t\t\t\t________________\n";
  cout<<"\t\t\t\t|2) Buyer\n";
   cout<<"\t\t\t\t________________\n";
  cout<<"\t\t\t\t|3) Exit\n";

  cout<<"\n\t Please select!";
  cin>>choice;
switch(choice)
{
  case 1:
  cout<<"Please login\n";
  cout<<"enter email\n";
  cin>>email;
  cout<<"enter password\n";
  cin>>password;

  if (email=="robby@gmail.com" && password=="zahid1122")
  {
    administrator();
  };
  
 };
  
}





int main()  
{  
   
  return 0;  
}  
