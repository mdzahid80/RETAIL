#include <iostream> 
#include <fstream> 

using namespace std;  

class retail
{
private:
    int product_code;
    float product_price;
    float product_discount;
    string product_name;
    

    public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void retail :: menu()
{
  m:
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
  cout<<"\t\t\t\t|2) Customer\n";
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
  }
  else{
    cout<<"Invalid Email/Password\nPlease retry";
  }
  break;
  
 
  case 2:
  {
    buyer();
  }
  case 3:
  {
    exit(0);
  }

  default:
  {
    cout<< "please select from the given options";
  }
}
goto m;
}

void retail :: administrator()
{
  m:
  int choice;
  cout<<"\n\n\n\t\t\t Administrator Menu\n";
  cout<<"\t\t\t\t___1) Add the Product\n";
  cout<<"\t\t\t\t                     \n";
  cout<<"\t\t\t\t___2) MOdify the Product\n";
  cout<<"\t\t\t\t                     \n";
  cout<<"\t\t\t\t___3) Delete the product\n";
  cout<<"\t\t\t\t                     \n";
  cout<<"\t\t\t\t___4) Back to main menu\n";

  cout<<"\n\n\t Please select an option";
  cin>>choice;

  switch(choice)
  {
    case 1:
    add();
    break;

    case 2:
    edit();
    break;

    case 3:
    rem();
    break;

    case 4:
    menu();
    break;

    default:
    cout<<"Invalid choice";
  }
  goto m;

}

void retail :: buyer()
{
  m:
  int choice;
  cout<<"\t\t\t  Buyer\n";
  cout<<"\t\t\t\t________________\n";
  cout<<"\t\t         \n";
  cout<<"\t\t\t1) Buy product \n";
  cout<<"\t\t\t       \n";
  cout<<"\t\t\t2) Go Back \n";
  cout<<"\t\t\tENter your Choice_\n";

  cin>>choice;
switch(choice)
{
  case 1:
  receipt();
  break;

 case 2:
  menu();

  default:
  cout<<"Invalid Choice";

}
goto m;
}

void retail :: add()
{
  m:
  fstream data;
  int c;
  int token;
  float p;
  float d;
  string n;

  cout<<"\n\n\n\t\t\t Add the product";
  cout<<"\n\n\t product code of the product";
  cin>>product_code;
  cout<<"\n\n\t name of the product";
  cin>>product_name;
  cout<<"\n\n\t product_price of the product";
  cin>>product_price;
  cout<<"\n\n\t discount on product";
  cin>>product_discount;

  data.open("database.txt", ios::in);
  if(!data)
  {
    data.open("database.txt",ios::app| ios::out);
    data<<" "<<product_code<<" "<<product_name<<" "<<product_price<<" "<<product_discount<<"\n";
    data.close();
  }
  else{
    data>>c>>n>>p>>d;
    while(!data.eof())
    {
      if(c== product_code)
      {
        token++;
      }
      data>>c>>n>>p>>d;
    }
    data.close();
  }
if (token==1)
{
  goto m;
}
else
{
data.open("database.txt",ios::app|ios::out);
data<<" "<<product_code<<" "<<product_name<<" "<<product_price<<" "<<product_discount<<"\n";
data.close();
}

cout<<"\n\n\t\t Record Inserted";
}

void retail :: edit()
{
  fstream data,data1;
  int pkey;
  int c;
  int token;
  float d;
  float p;
  string n;

  cout<<"\n\t\t\t MOdify the product";
  cout<<"\n\t\t\t Product code :";
  cin>>pkey;

  data.open("database.txt",ios::in);
  if(!data)
  {
    cout<<"\n\nFile Doesn't exist!";
  }
  else{
    data1.open("database.txt", ios::app|ios::out);

    data>>product_code>>product_name>>product_price>>product_discount;
    while(!data.eof())
    {
      if(pkey==product_code)
      {
        cout<<"\n\t\t Product new code";
        cin>>c;
        cout<<"\n\t\t NAME Of the Produuct";
        cin>>n;
        cout<<"\n\t\t product_price";
        cin>>p;
        cout<<"\n\t\t discount ";
        cin>>d;
        data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
        cout<<"\n\n\t\t Reord edited";
        token++;
      }
      else{
        data1<<" "<<product_code<<" "<<product_name<<" "<<product_price<<" "<<product_discount; 
      }
      data>>product_code>>product_name>>product_price>>product_discount;
    }
    data.close();
    data1.close();

    remove("datatbase.txt");
    rename("database1.txt","database.txt");

    if (token==0){
      cout<<"\n\n Record not found";
    }
  }
}

void retail::rem()
{
  fstream data,data1;
  int pkey;
  int token=0;
  cout<<"\n\n\t delete product";
  cout<<"\n\n\t Product code:";
  cin>>pkey;
  data.open("database.txt",ios::in);
  if(!data)
  {
    cout<<"file doesnt found";
  }
  else{
    data1.open("database1.txt",ios::app|ios::out);
    data>>product_code>>product_name>>product_price>>product_discount;
    while(!data.eof())
    {
      if(product_code==pkey)
      {
        cout<<"\n\n\t Product deleted succesfully";
        token++;
      }
      else
      {
        data1<<" "<<product_code<<" "<<product_name<<" "<<product_price<<" "<<product_discount<<"\n";
      }
      data>>product_code>>product_name>>product_price>>product_discount; 
    }
    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt","database.txt");

    if(token==0)
    {
      cout<<"\n\n Record not found";
    }
  }
}

void retail::list()
{
  fstream data;
  data.open("database.txt",ios::in);
  cout<<"\n\n|_____________________________\n";
  cout<<"ProNo\t\t NAME\t\t product_price\n";
  cout<<"\n\n______________________________\n";
  data>>product_code>>product_name>>product_price>>product_discount;
  while(!data.eof())
  {
    cout<<product_code<<"\t\t"<<product_name<<"\t\t"<<product_price<<"\n";
    data>>product_code>>product_name>>product_price>>product_discount;
  }
  data.close();
}

void retail:: receipt()
{
  m:
  fstream data;

  int arrc[100];
  int arrq[100];
  char choice;
  int c=0;
  float amount=0;
  float product_discount=0;
  float total=0;

  cout<<"\n\n\t\t\t\t RECEIPT";
  data.open("database.txt",ios::in);
  if(!data)
  {
    cout<<"\n\n Empty daatabase";
  }
  else
  {
    data.close();

    list();
    cout<<"______________________";
    cout<<"                      ";
    cout<<"Place order";
    cout<<"                      ";
    cout<<"______________________";
    do
    {
      cout<<"\n\nEnter product code";
      cin>>arrc[c];
      cout<<"\n\nEnter the product quantity";
      cin>>arrq[c];
      for(int i=0;i<c;i++)
      {
        if (arrc[c]==arrc[i])
        {
        
         cout<<"\n\n duplicate product code. Please try  again";
         goto m;
        }
      }
      c++;
      cout<<"\n\n do you want to buy another product? press y for yes else n for no!";
      cin>>choice;
    
    }
  while(choice =='y');

  cout<<"\n\n\t\t\t______________RECEIPT___________\n";
  cout<<"\n product no\t product name\t product quantity\tproduct_price\tamount\tAmount with discount";

  for(int i=0;i<c;i++)
  {
    data.open("database.txt",ios::in);
    data>>product_code>>product_name>>product_price>>product_discount;
    while(!data.eof())
    {
      if(product_code==arrc[i])
      {
        amount=product_price*arrq[i];
        product_discount=amount-(amount*product_discount/100);
        total=total+product_discount;
        cout<<"\n"<<"\t"<<product_code<<"\t\t\t"<<product_name<<"\t\t\t"<<arrq[i]<<"\t\t"<<product_price<<"\t\t"<<amount<<"\t\t"<<product_discount;
      }
      data>>product_code>>product_name>>product_price>>product_discount;
    }
  }
  data.close();
}

cout<<"\n\n________________________________";
cout<<"\n Total Amount :"<<total;
}

int main()  
{  
   retail s;
   s.menu();
  return 0;  
}  
