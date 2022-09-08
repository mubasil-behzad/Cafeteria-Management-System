#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<string.h>
#include<Windows.h>

using namespace std;

struct Item
{
	char name[50];
	float rating;
	float price;
	int food_Id_No;
	struct Item *next;
	struct Item *prev;
};

int cust_Id=1;
struct Item* head;
struct Item* last;
int Today_customer=0;
float total_income=0;

struct order_hist
{
	int Customer_ID;
	int items [10][2];
	float amount;
	char date[11];
	struct order_hist *next;
	struct order_hist *prev;	
};
    struct order_hist *head1;
	struct order_hist *last1;
	struct Item* getnewNode (char a[],float p, int fin)
	{
		struct Item* temp=(struct Item*) malloc(sizeof(struct Item));
		temp->food_Id_No=fin;
		strcpy(temp->name, a);
		temp->rating=4.0;
		temp->price=p;
		temp->next=NULL;
		temp->prev=NULL;
		return temp;	
	}
	
	void insert(char n[],float p,int fin)
	{
		struct Item* temp1=getnewNode(n,p,fin);
		if(head==NULL)
		{
			head=temp1;
			last=temp1;
		}
		else
		{
			temp1->prev=last;
			last->next=temp1;
			last=temp1;
		}
		
	}
	
	struct order_hist* getnewNode_hist()
	{
		struct order_hist* temp=(struct order_hist*)malloc(sizeof(struct order_hist));
		temp->next=temp->prev=NULL;
		return (temp);
	}
	
	void display ()
	{
		cout<<"                               ----------------                                  "<<endl;
		cout<<"-------------------------------------MENU----------------------------------------"<<endl;
		cout<<"                               ----------------                                  "<<endl;
		cout<<"\t\tINDEX       ITEM NAME      PRICE       RATING"<<endl;
		
		struct Item* temp=head;
		if(head==NULL)
		{
			cout<<"Empty";
		}
		
		while (temp!=NULL)
		{
			cout<<"\n\t\t  "<<temp->food_Id_No<<"\t    "<<temp->name<<"\t   "<<temp->price<<"\t  "<<temp->rating<<endl;
			temp=temp->next;
		}
		cout<<"-----------------------------------------------------------------------------------"<<endl;	
		
	}
	
	int login()
	{
		char username[20];
		char userpswrd[15];
		int i;
		cout<<"------------------------------------------------------------------------------------"<<endl;
		cout<<"Enter your username => ";
		cin>>username;
		cout<<"Enter your Password Of 4 Characters => ";
		for(i=0;i<4;i++)
		{
		userpswrd[i]=getch();
		cout<<"*";	
		}
		userpswrd[i]='\0';
		
		if(!strcmp(username,"admin") || strcmp(userpswrd,"1234"))
		{
			cout<<"\nLogged In successful\n";
			system("PAUSE");
			system("CLS");
			return 1; 
			
		}
		else
		{
			cout<<"\nIncorrect Username or Password\n";
			system("PAUSE");
			
			return 0;
		}
		
	}
	
	void order()
	{
		int a[10][2];
		int n,j=0,i=0;
		
		do{
			cout<<"\n------------------------------------------------------------------------------------"<<endl;
			cout<<"Please enter the food_ID, Number of item and its quantity => ";
			for(i=0;i<2;i++)
			{
				cin>>a[j][i];
			}
			j++;
			cout<<"\nYou want more item 1 for Yes 2 for No => ";
			cin>>n;
		}while(n==1);
		float total_amount=0.0;
		char Name[25];
		char Date[15];
		cout<<"\nEnter your Name => ";
		cin>>Name;
		cout<<"Enter today's date => ";
		cin>>Date;
		int k=0;
		cout<<"------------------------------------------------------------------------------------"<<endl;
		cout<<"                                       Bill                                         "<<endl;
		 
		cout<<"name => "<<Name<<endl;
		
		cout<<"date => "<<Date<<endl;
		cout<<"Items You Buy Are : "<<endl;
		cout<<endl;
		for(k=0;k<j;k++)
		{
			struct Item* temp=head;
			while(temp->food_Id_No!=a[k][0])
			{
				temp=temp->next;
			}
			cout<<"------------------------------------------------------------------------------------"<<endl;
			
			cout<<"\t\t\t\n"<<temp->food_Id_No<<" "<<temp->name<<" "<<a[k][1]<<"  "<<(a[k][1]*(temp->price))<<endl;
			total_amount+=(a[k][1]*(temp->price));
			
		}
		cout<<"------------------------------------------------------------------------------------"<<endl;
		cout<<"Total payable amount is => "<<total_amount<<endl;
		cout<<"------------------------------------------------------------------------------------"<<endl;
		
		struct order_hist* temp2=getnewNode_hist();
		temp2->amount=total_amount;
		temp2->Customer_ID=cust_Id++;
		
		int p,s;
		
		for(p=0;p>j;p++)
		{
			for(s=0;s<2;s++)
			{
				temp2->items[p][s]=a[p][s];
			}
		}
		if(head1==NULL)
		{
			head1=last1=temp2;
		}
		
		else
		{
			last1->next=temp2;
			temp2->prev=last1;
			last1=temp2;
		}
		
		strcpy(temp2->date,Date);
		
		Today_customer++;
		total_income+=total_amount;
		
	}
	
	
	void display_rd_hist()
	{
		cout<<"                                    ----------                                     "<<endl;
		cout<<"-----------------------------------ORDER HISTORY-----------------------------------"<<endl;
		cout<<"                                    ----------                                     "<<endl;
		cout<<"SR-NO        DATE       TOTAL AMOUNT"<<endl;
		
		struct order_hist* temp=head1;
		if(head1==NULL)
		{
			cout<<"Empty";
		}
		
		while(temp!=NULL)
		{
			cout<<"\t\t\t",temp->Customer_ID,temp->date,temp->amount;
			temp=temp->next;
		}
	}
	
	main()
	{
		head=NULL;
		last=NULL;
		
		insert("Burger    ",70.23,1);
		insert("Pizza   ",235.67,2);
		insert("Cake    ",750.83,3);
		insert("Coffie    ",70.23,4);
		insert("Ice-cream ",70.23,5);
		insert("Sandwich ",60.23,6);
		insert("Grill   ",52.29,7);
		insert("Nun-bread ",35.13,8);
		insert("Cold drinks",20.13,9);
		
		int ch;
		int choice;
		 do{
		 	//system("PAUSE");
		 	system("CLS");
		 	cout<<"------------------------------------------------------------------------------------"<<endl;
		 	cout<<"......Press 1 => Food Part"<<endl;
		 	cout<<"......Press 2 => Admin Panel"<<endl;
		 	cout<<"......Press 3 => Exit"<<endl;
		 	
		 	cout<<"Enter your choice => ";
		 	cin>>choice;
		 	
		 	system("CLS");
		 	switch(choice)
		 	{
		 		case 1:
		 			
		 			int ex;
		 			system("CLS");
		 			do{
		 				
						//cout<<"\n\n..........................................\n";
						cout<<"-----------------------------------------------------------------------------------"<<endl;
		 				cout<<"Press 1 => Food List\nPress 2 => Order\n";
		 				int n;
		 				cout<<"Enter your choice => ";
		 				cin>>n;
		 				switch(n)
		 				{
		 					case 1: 
		 					{
		 						
		 						display();
		 						
							 }
							 
		 					break;
		 					case 2:
							 { 
							 	order();
							 	system("PAUSE");
							 	system("CLS");
							 }
		 					break;
		 					
						 }
						 cout<<"-----------------------------------------------------------------------------------"<<endl;
						 cout<<"\nPress 1 => Food Part\nPress 2 => Main Menu\n";
						 cout<<"Enter your choice => ";
						 cin>>ex;
					 }while(ex==1);
					 break;
					 
					 case 2:
					 	cout<<" \n ";
					 	int k=login();
					 	int e;
					 	if(k==1)
					 	{
					 		do{
					 			cout<<"\n------------------------------------------------------------------------------------"<<endl;
					 			cout<<"Press 1 =>    ADD NEW DISH"<<endl;
					 			cout<<"Press 2 =>    TODAY'S TOTAL INCOME"<<endl;
					 			cout<<"Press 3 =>    TODAY TOTAL NO. OF CUSTOMER"<<endl;
					 			cout<<"Press 4 =>    ORDER HISTORY"<<endl;
					 			cout<<"Press 5 =>    LIST OF ITEM"<<endl;
					 			cout<<"------------------------------------------------------------------------------------"<<endl;
					 			cout<<"Enter your choice => ";
					 			
					 			cin>>ch;
					 			system("CLS");
					 			switch(ch)
					 			{
					 				case 1:
					 					cout<<"\n";
					 					float p;
					 					int fin;
					 					char n[50];
					 					cout<<"------------------------------------------------------------------------------------"<<endl;
					 					cout<<"\nEnter the name of item => ";
					 					cin>>n;
					 					cout<<"Enter the price of item => ";
					 					cin>>p;
					 					cout<<"Enter the food_id_no of item => ";
					 					cin>>fin;
					 					
					 					
					 					insert(n,p,fin);
					 					cout<<"------------------------------------------------------------------------------------"<<endl;
					 					cout<<"                             New Dish is Added Successfully..........               "<<endl;               
					 					cout<<"------------------------------------------------------------------------------------"<<endl;
					 					cout<<"\n";
					 					break;
					 					
					 					case 2:
					 					cout<<"------------------------------------------------------------------------------------"<<endl;
					 					cout<<"                             Today's total income is => "<<total_income<<endl;               
					 					cout<<"------------------------------------------------------------------------------------"<<endl;
					 					system("PAUSE");
					 					system("CLS");
					 					break;
					 					
					 					case 3:
					 					cout<<"------------------------------------------------------------------------------------"<<endl;
					 					cout<<"                       Today total No of Customer Visited Id => "<<Today_customer<<endl;               
					 					cout<<"------------------------------------------------------------------------------------"<<endl;
					 					system("PAUSE");
					 					system("CLS");
					 					break;
					 					
					 					case 4:	
					 					cout<<"------------------------------------------------------------------------------------"<<endl;
					 					cout<<"                                       Order Summary                                "<<endl;              
					 					cout<<"------------------------------------------------------------------------------------"<<endl;
					 					display_rd_hist();
					 					cout<<"\n";
					 					system("PAUSE");
					 					system("CLS");
					 					break;
					 						
					 						case 5:
					 							cout<<"\n";
					 							display();
					 							system("PAUSE");
					 							system("CLS");
					 							break;
								 }
							 }while(ch<=5);
						 }
			 }
		 	
		 }while(choice<=5);
	}
	
