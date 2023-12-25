#include<iostream>
#include<string>
#include<fstream>
#include<windows.h> /// use for delay 
#include<ctime>  // use to get system time
using namespace std;
struct node
{
	string B_n; 	//b_n for book name and b_dis for distance 
	int b_id,b_price,b_quantity,b_rating,b_dis;
	node* next;
	node* prev;
	
};

class finder 
{
	protected:	
	string name,B_name;
	int price,Book_ID,quant;
	int rating;
	
	bool flag,flag2;
	int Dis; 	//distance
	int min;	//min => minimum price
	string search_Book;
	//for order details
	string email,addres;
	string contact;
	
	public:
	int count=0;
	node* head;
	node* tail;
	finder ()
	{
		name="";
		B_name="";
		email = addres = contact = "";
		price=Book_ID=quant=rating=NULL;
		head=tail=NULL;	
	}
	void find();
    void order();
	//void show();
	string rep(string a);
	void most_rated();
	void control_panel();
	void min_price();
	void print_bill(int id);
	void near_book();
	void nearest_store();
	bool IsEmpty() 
	{
		if(head==NULL && tail==NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void InsertAtTail(string n,int b_d,int b_i,int b_pr,int b_quant,int b_rat)
		{
			node* newer = new node;
			
			newer->B_n = n;
			newer->b_id = b_i;
			newer->b_price = b_pr;
			newer->b_quantity = b_quant;
			newer->b_rating = b_rat;
			newer->b_dis = b_d;
		if(IsEmpty())
			{
				newer->next=NULL;
				newer->prev=NULL;
				head = newer;
				tail=newer;
				count++;
			}
			else
			{
				tail->next=newer;
				newer->prev=tail;
				newer->next = NULL;
				tail = newer;
				count++;
			}
			
			//return head;
		}
		void display()
		{
			cout<<"Book name \tBook ID			 	Price			    Quantity		rating	"<<endl;
		
			if(IsEmpty())
			{
				cout<<"\nYou Have No Searched Book In Recents...";
				
			}
			else
			{
				//cout<<"\n total count:"<<count;
				node* temp = tail;
				cout<<"\n";
				while(temp!=NULL)
				{
					cout<<"\n "<<temp->B_n<<"\t\t"<<temp->b_id<<"\t\t\t\t"<<temp->b_price<<"\t\t\t"<<temp->b_quantity<<"\t\t"<<temp->b_rating;
					temp=temp->prev;
				}
			}
		}
	
    ~finder ()
		{
		
		}
		
};
		
void finder::control_panel()
{
	
	system("cls");
	cout<<"\t\t\t\t    ************************************\n";
	cout<<"\t\t\t\t    ||| Wellcome to book Finder Menu |||\n";
	cout<<"\t\t\t\t    ************************************\n";
	cout<<"\n\nPress '1' to search a book.";
	cout<<"\n\nPress '2' to Find nearby store.";
	cout<<"\n\nPress '3' to find 4-Star or above rated books.";
	cout<<"\n\nPress '4' to see recent searched books.";
	cout<<"\n\nPress '5' to exit.";
	cout<<"\n\nEnter Your Choice:->  ";

}

void finder::find()
{
	fstream file,file2;
	cout<<"\nEnter book name: ";
	cin.ignore();
	getline(cin,search_Book);
	//cin>>search_Book;
	//a=x;
	file.open("store.txt",ios::in);		
	if(!file )
	{
		cout<<"\nABC Store NOT Available";
	}
	else
	{
		cout<<"Book name \tBook ID		 	Price			    Quantity		rating	"<<endl;
						
		while (!file.eof())
		{
				file>>B_name>>Book_ID>>price>>quant>>rating>>Dis;
				if ( rep(search_Book) == B_name)
				{
					InsertAtTail(B_name,Dis,Book_ID,price,quant,rating);
					count++;
					if(B_name.size() <= 6)
					{
						cout<<B_name<<"\t\t"<<Book_ID<<"\t\t\t"<<price<<"\t\t\t\t"<<quant<<"\t\t"<<rating<<endl;
					}
					else
						{
							cout<<B_name<<"\t\t"<<Book_ID<<"\t\t"<<price<<"\t\t\t\t   "<<quant<<"\t"<<rating<<endl;
						}
				}
		}
	}
	
	file.close();
	file2.open("XYZ_Store.txt",ios::in);		
	if(!file2 )
	{
		cout<<"\nXYZ Store Not Available";
	}
	else
	{
		
		while (!file2.eof())
		{
		
			file2>>B_name>>Book_ID>>price>>quant>>rating>>Dis;
			if ( rep(search_Book) == B_name )
			{
				InsertAtTail(B_name,Dis,Book_ID,price,quant,rating);
						
				if(B_name.size() <= 6)
				{
					count++;
					cout<<B_name<<"\t\t"<<Book_ID<<"\t\t\t"<<price<<"\t\t\t\t"<<quant<<"\t\t"<<rating<<endl;
				}
				else
				{
					cout<<B_name<<"\t\t"<<Book_ID<<"\t\t"<<price<<"\t\t\t\t   "<<quant<<"\t"<<rating<<endl;
				}
			}
		}
	}
	file2.close();
		
		//display(head);
		
//	cout<<"count\t"<<count;	
		
	}
	


void finder::most_rated()
{
	int rate = 0;
	cout<<"\nEnter minimum rating (1 to 5):";
	cin>>rate;
	node* temp= head;
	cout<<"Book ID \tBook name		 	Price			Quantity	rating	"<<endl;
        while(temp != NULL)
        {
			if(search_Book == temp->B_n)
        	{
	        	if(rate <= temp->b_rating )
        		{
        			
        			cout<<"\n "<<temp->b_id<<"\t\t"<<temp->B_n<<"\t\t\t\t"<<temp->b_price<<"\t\t\t"<<temp->b_quantity<<"\t\t"<<temp->b_rating;
					
				}
			}
			temp = temp->next;
		}
}

void finder::min_price()
{
	bool fl = false;
	char x=NULL;
	node* temp= head;
	cout<<"\nEnter minimum price: ";
	cin>>price;
	cout<<"Book ID \tBook name		 	Price			Quantity	rating	"<<endl;
        while(temp != NULL)
        {
        	
	        	if(price >= temp->b_price && search_Book == temp->B_n)
        		{
        			fl = true;
					cout<<"\n "<<temp->b_id<<"\t\t"<<temp->B_n<<"\t\t\t\t"<<temp->b_price<<"\t\t\t"<<temp->b_quantity<<"\t\t"<<temp->b_rating;
					
				}
			
			temp = temp->next;
		}
		if(fl == false)
		{
			cout<<"\nNo Book Available in this price.\n\nPlease try again.";
			
		}
		cout<<"\n\nWant to try another price? (y/n): ";
		cin>>x;
		if(toupper(x) == 'Y')
		{
			min_price();	
		}
		
	

}

void finder::near_book()
{
	bool fl = false;
	char x=NULL;
	node* temp= head;
	cout<<"\nEnter minimum distance (like '600'): ";
	cin>>Dis;
	cout<<"Book ID \tBook name		 	Price			Quantity	rating	"<<endl;
        while(temp != NULL)
        {
        	if( Dis >= temp->b_dis && search_Book == temp->B_n)
        	{
        		
    			cout<<"\n "<<temp->b_id<<"\t\t"<<temp->B_n<<"\t\t\t\t"<<temp->b_price<<"\t\t\t"<<temp->b_quantity<<"\t\t"<<temp->b_rating;
				fl = true;
				
			}
			temp = temp->next;
		}
		
		if(fl == false)
		{
			cout<<"\nNo Book Available in this Area.\n\nPlease try again.";
			
		}
		cout<<"\n\nWant To Try Another Location? (y/n): ";
		cin>>x;
		if(toupper(x) == 'Y')
		{
			near_book();	
		}
}

void finder::order()	
{
	char x;
	//selected book id
	int id;
	cout<<"\nEnter Book ID to select book: ";
	cin>>id;
	node* temp= head;
	while(temp != NULL)
    {
        	
	        	if(id == temp->b_id)
        		{
        			cout<<"\n\nBook Selected.....";
			
					Sleep(500);  //sleeps for 500 millisecond
					system("cls");
					fstream file;
					cout<<"\t\t\t\t    ***************************************\n";
					cout<<"\t\t\t\t    ||||||||||| enter order details ||||||||\n";
					cout<<"\t\t\t\t    ***************************************\n";
					cout<<"\n\n\t\t Enter First Name = ";
					cin>>name;
					cout<<"\n\n\t\t Enter Contact Number (11 Digits)= ";
					cin>>contact;
					cout<<"\n\n\t\t Enter Email= ";
					cin>>email;
					cout<<"\n\n\t\t Enter Address= ";
					cin>>addres;
					
					cout<<"\n\n\t\t Press 'Y' to confirm your order:";
					cin>>x;
					if(toupper(x) == 'Y')
					{
						
						cout<<"\n\nOrder Sucessfuly Placed......";
						file.open("invoice.txt",ios::out|ios::app);		// :: means rasolation  oprater
						file<<name<<"\t\t"<<"\t\t"<<contact<<"\t\t"<<email<<"\t\t"<<addres<<"\n";
						file.close();
					//function to print bill
						print_bill(id);
					}
					else 
						{
						//return to main menu
							return;
					}
        			
        		}
			
			temp = temp->next;
		
	
	}
}
void finder::print_bill(int id)
{
	int x;
	fstream file;	
		cout<<"\n\t------------- E-Book Store --------";
		cout<<"\n\t--------Sector C,DHA Phase-VI Lahore--------";
		// current date/time with retun value(0) based on current system
		string arr[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
		time_t now = time(0);   //milisecounds
		tm *ltm2 = localtime(&now);
		cout<<"\n\n\tName         :"<<name;
		cout<<"\n\n\tContact      :"<<contact;
		node* temp= head;
        while(temp != NULL)
        {
        	if(id== temp->b_id)
        	{
        		
        			cout<<"\n\n\tBook ID      :"<<temp->b_id;
        			x= temp->b_id;
					cout<<"\n\n\tBook Name    :"<<temp->B_n;
					cout<<"\n\n\tBook Price   :"<<temp->b_price;
					break;
        		
			}
                temp = temp->next;
        }
		
		cout<<"\n\n\tAddress      :"<<addres;
		cout<<"\n\n\tEmail Address:"<<email;
		cout<<"\n\t\t\t\tPrint Date:"<< ltm2->tm_mday<<"/"<<arr[ltm2->tm_mon]<<"/"<< 1900 + ltm2->tm_year;
		cout<<"\n\t\t\t\tHelp Line: 15 ";
		
		//update files after placing the order
	fstream exfile,newfile;	
	//cout<<"X"<<x;
	if (x <= 40)
	{
	
		exfile.open("store.txt",ios::in);
		newfile.open("project1.txt",ios::app|ios::out);
					exfile>>B_name>>Book_ID>>price>>quant>>rating>>Dis;
					while(!exfile.eof())
					{
						
						exfile>>B_name>>Book_ID>>price>>quant>>rating>>Dis;
						if(x== Book_ID)
	        			{
	        				newfile<<B_name<<"\t\t\t"<<Book_ID<<"\t"<<price<<"\t"<<quant-1<<"\t"<<rating<<"\t"<<Dis<<"\n";
	        				exfile>>B_name>>Book_ID>>price>>quant>>rating>>Dis;
						}
						else
						{
							newfile<<B_name<<"\t\t\t"<<Book_ID<<"\t"<<price<<"\t"<<quant<<"\t"<<rating<<"\t"<<Dis<<"\n";
						}
					}
		
		exfile.close();
		newfile.close();
		remove("store.txt");
		rename("project1.txt","store.txt");
	}
	else{
	exfile.open("XYZ_Store.txt",ios::in);
	newfile.open("project1.txt",ios::app|ios::out);
	exfile>>B_name>>Book_ID>>price>>quant>>rating>>Dis;
				while(!exfile.eof())
				{
					if(x== Book_ID)
	        			{
							newfile<<B_name<<"\t\t\t"<<Book_ID<<"\t"<<price<<"\t"<<quant-1<<"\t"<<rating<<"\t"<<Dis<<"\n";
	        				exfile>>B_name>>Book_ID>>price>>quant>>rating>>Dis;
						}
						else
						{
							newfile<<B_name<<"\t\t\t"<<Book_ID<<"\t"<<price<<"\t"<<quant<<"\t"<<rating<<"\t"<<Dis<<"\n";
						}
				
		
		exfile.close();
		newfile.close();
		remove("XYZ_Store.txt");
		rename("project1.txt","XYZ_Store.txt");
	}
	}
	
}
void finder::nearest_store()
{
	fstream file,file2;
	bool flag,flag2;
	flag = flag2 =false ;
	int loc;
	cout<<"\nEnter location like(500): ";
	cin>>loc;    
	file.open("store.txt",ios::in);		
	if(!file )
	{
		cout<<"File no exist";
	}
	else
	{
		while (!file.eof())
		{
				file>>B_name>>Book_ID>>price>>quant>>rating>>Dis;
				if(Dis >= 300 && Dis <= loc)
					{
						flag=true;
						cout<<"\nABC BOOK STORE, St#6 ,shop# 40 . ";
						break;
						
						}	
	}
	}
	file.close();
	file2.open("XYZ_Store.txt",ios::in);		
	if(!file2 )
	{
		cout<<"File no exist";
	}
	else
	{
		
		while (!file2.eof())
		{
		
			file2>>B_name>>Book_ID>>price>>quant>>rating>>Dis;
			//cout<<stoi (Dis);
				if( Dis >= 300 && Dis <= loc)
					{
						flag2=true;
						cout<<"\nXYZ BOOK STORE, St#7, shop# 48.";
						break;
						
						}
		}
	}
	file2.close();
	
	if(flag == false && flag2 == false)
	{
		cout<<"\nNo store available in this area.\n";
	}

}
string finder::rep(string a)
{

  char c[]={'_',' '};
	for(int i=0;i<(a.size()-1);i++)
	{
		if (a[i] == c[1])
		{
		a[i]= c[0];
		}

	}
	return a;
}

int main()
{
    finder f;
	char x;
	int ch;
	do
	{
	    f.control_panel();
		cin>>ch;
		switch (ch)
		{
			case 1:
				fi:
				f.find();
				if(f.count == 0)
				{
					cout<<"Not Available......";
				}
				else
				{
					int u=NULL;  // for selection
					char z=NULL,c=NULL; // for user choice yes or no
					
					do{
						cout<<"\nPress '1' to add filters.\nPress '2' to buy book.\n Press '3' to search another Book.";
						cout<<"\nEnter your choise: ";
						cin>>u;			//user input
						if(u == 1)
							{
							int cho;
							do{
								cout<<"\nPress '1' to find book that`s nearest to your location.";
								cout<<"\nPress '2' to find book at lowest price.";
								cout<<"\nPress '3' to find book that`s top rated.";
								cin>>cho;
								switch (cho)
								{
									case 1:
										f.near_book();
										break;
									case 2:
										f.min_price();
										break;
									case 3:
										f.most_rated();
										break;
									default:
										cout<<"\nInvalid choise....try again";
										break;
							}
							cout<<"\n\nWant to add filters again? (y/n):";
							cin>>c;
							}while (toupper(c) == 'Y');
						}
						else if(u == 2)
						{
							f.order();
						}
						else if(u == 3)
						{
							// go to again find function
							goto fi;
							//f.find();
						}
						else
						{
							cout<<"\n\nInvalid choise....Please try again.\n\nWant to try again? (y/n):";
							cin>>z;
						}
						cout<<"\n\nGoto to the top menu-> Press (y/n):";
						cin>>z;
						}while (toupper(z) == 'Y');
					}
					break;
				case 2:
					f.nearest_store();
					break;
				case 3:
					f.find();
					f.most_rated();
					break;
				case 4:
					f.display();
					break;
				case 5:
					exit(0);
				default:
					break;
		}

		cout<<"\n\n\tPress 'y' to continue: ";
		cin>>x;
	} while (x =='y');
   // f.insert();
	//f.find();*/
    return 0;

}

