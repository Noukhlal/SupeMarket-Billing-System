#include<iostream>
#include<fstream>
using namespace std;

class Shopping{
	private:
		int pcode;
		float price;
		float discount;
		string pname;
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

void Shopping:: menu()
{
	m:
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t\t________________________________________________\n";
	cout<<"\t\t\t\t                                				   \n";
	cout<<"\t\t				Supermarket Main Menu          	   \n";
	cout<<"\t\t\t\t                                                \n";
	cout<<"\t\t\t\t________________________________________________\n";
	cout<<"\t\t\t\t                                                \n";
	cout<<"\t\t\t\t| 1) Administrator  |\n";
	cout<<"\t\t\t\t|                   |\n";
	cout<<"\t\t\t\t| 2) Buyer          |\n";
	cout<<"\t\t\t\t|                   |\n";
	cout<<"\t\t\t\t| 3) Exit           |\n";
	cout<<"\t\t\t\t|                   |\n";
	cout<<"\t\t\t\t Please Select : ";
	cin>>choice;
	switch(choice){
		case 1:
		{
			cout<<"\n\n\t\t\t\t Please Login \n";
			cout<<"\t\t\t\t Enter Email : ";
			cin>>email;
			cout<<"\t\t\t\t Password :";
			cin>>password;
			
			if(email=="rohan@gmail.com" && password=="rohan@342")
			{
				administrator();	
			}
			else{
				cout<<"\nInvlalid email/password"<<endl;
			}
			break;
		}
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
			cout<<"\n\t\t\t\tPlease selct from the given option"<<endl;
		}
	}
	goto m;
}

void Shopping::administrator()
{
	m:
	int choice;
	cout<<"\n\n\n\t\t\t\t Administrator menu\n";
	cout<<"\t\t\t\t|_____1) Add the product_____|\n";
	cout<<"\t\t\t\t|                           |\n";
	cout<<"\t\t\t\t|_____2) Modify the product__|\n";
	cout<<"\t\t\t\t|                           |\n";
	cout<<"\t\t\t\t|_____3) Delete the product__|\n";
	cout<<"\t\t\t\t|                           |\n";
	cout<<"\t\t\t\t|_____4) Back to main menu___|\n";
	cout<<"\t\t\t\t|                           |\n";
	cout<<"\n\t\t\t\t Please enter your chocie : ";
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
			cout<<"Invalid choice !";
	}
	goto m;
}

void Shopping::buyer()
{
	m:
	int choice;
	cout<<"\n\t\t\t\t Buyer \n";
	cout<<"                 \n";
	cout<<"\t\t\t\t 1) Buy product \n";
	cout<<"                 \n";
	cout<<"\t\t\t\t 2) Go back \n";
	cout<<"                 \n";
	cout<<"\t\t\t\t Enter your choice : ";
	cin>>choice;
	
	switch(choice)
	{	
		case 1:
			receipt();
			break;
		case 2:
			menu();
		default:
			cout<<"Invalid choice !";
	}
	goto m;
}

void Shopping ::add()
{	
	m:
	fstream data;
	int c;
	int token;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t\t\t Add the product";
	list();
	cout<<"\n\n\t\t\t\t Product code of the product : ";
	cin>>pcode;
	cout<<"\t\t\t\t Name of the product : ";
	cin>>pname;
	cout<<"\t\t\t\t Price of the product : ";
	cin>>price;
	cout<<"\t\t\t\t Discount on product : ";
	cin>>discount;
	
	data.open("database.txt",ios::in);
	if(!data){
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
		data.close();
	}
	else{
		data>>c>>n>>p>>d;
		
		while(!data.eof())
		{
			if(c == pcode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	
		if(token==1)
			goto m;
		else
		{
			data.open("database.txt",ios::app|ios::out);
			data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
			data.close();
		}
	}
	
	cout<<"\n\n\t\t\t\t\t Record inserted !";
}

void Shopping ::edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\t\t\t\t Modify the record ";
	list();
	cout<<"\n\t\t\t\t Prodct code : ";
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"\n\n\t\t\t\tFile does not exist !";
	}
	else{
		data1.open("database1.txt",ios::app|ios::out);
		
		data>>pcode>>pname>>price>>discount;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\t\t\t\t Product new code : ";
				cin>>c;
				cout<<"\t\t\t\t Name of the product : ";
				cin>>n;
				cout<<"\t\t\t\t Price : ";
				cin>>p;
				cout<<"\t\t\t\t Discount : ";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\t\t\t\t Record edited !";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
			}
			
			data>>pcode>>pname>>price>>discount;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n\t\t\t\t Record not found sorry !";
		}
	}
	
}

void Shopping::rem()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t\t\t\t Choose the product want to remove.";
	list();
	cout<<"\n\n\t\t\t\t Product code : ";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\t\t\t\tFile does not exist";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>discount;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t\t\t\t Prodcut deleted successfully.";
				token++;
			}
			else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
			}
			data>>pcode>>pname>>price>>discount;	
		}
		data.close();
		data1.close();	
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0){
			cout<<"\n\n\t\t\t\t Record not found.";
		}
	}
}

void Shopping::list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n\t\t\t\t__________________________________________________\n";
	cout<<"\t\t\t\tP No \t\tP Name \t\tPrice \n";
	cout<<endl;
	data>>pcode>>pname>>price>>discount;
	while(!data.eof())
	{
		cout<<"\t\t\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>discount;
	}
	data.close();
}

void Shopping::receipt()
{
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount;
	float discount=0;
	float total=0;
	
	cout<<"\n\n\t\t\t\t List of Product";
	data.open("database.txt",ios::in);
	
	if(!data)
	{
		cout<<"\n\n Empty database. ";
	}
	else
	{
		data.close();
		list();
		cout<<"\n\t\t\t\t____________________________________________\n";
		cout<<"\t\t\t\t            Please place the order          \n";
		cout<<"\t\t\t\t            	   ------XXX-----\n";
		
		do{
			cout<<"\n\n\t\t\t\t Enter the Product code :";
			cin>>arrc[c];
			cout<<"\t\t\t\t Enter the Product quantity : ";
			cin>>arrq[c];
	
			for(int i=0;i<c;i++)
			{
				if(arrc[c]==arrc[i])
				{
					cout<<"\n\n\t\t\t\t Duplicate product code. Please try again!";
					goto m;
				}
			}
			c++;
			m:
			cout<<"\n\n\t\t\t\t Do you want to buy another product ?\n\t\t\t\t if yes than press y else n : ";
			cin>>choice;	
		}
		while(choice=='y');
		
		cout<<"\n\n\t\t\t\t_________________________________________________RECEIPT__________________________________________________\n";
		cout<<"\n\t\t\t\tProduct No \tProduct Name \tProduct Quantity \tPrice \t\tAmount \t\tAmount with discount\n";
		
		for(int i=0;i<c;i++)
		{
			data.open("database.txt",ios::in);
			data>>pcode>>pname>>price>>discount;
			while(!data.eof())
			{
				if(arrc[i]==pcode)
				{
					amount=price*arrq[i];
					discount=amount-(amount*discount/100);
					total=total+discount;
					cout<<"\n\t\t\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<discount; 
				}
				data>>pcode>>pname>>price>>discount;
			}
			data.close();
		}	
	}
	cout<<"\n\n\t\t\t\t_________________________________________________XXXXXXX__________________________________________________\n";
	cout<<"\n\t\t\t\t Total Amount : "<<total<<"\n\n";
}

int main()
{
	system("color 4e");
	Shopping s;
	s.menu();
	return 0;
}
