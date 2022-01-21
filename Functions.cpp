#include <fstream>
#include <iostream>
#include<bits/stdc++.h>
#include "Header.h"

using namespace MYNAMESPACE;
using namespace std;

void bookshope::control_panel()  
{
	
	cout << "\n\n\t\t\t\tCONTROL PANEL";
	cout << "\n\nPRESS 1 for **ADD BOOK**";
	cout << "\nPRESS 2 for **DISPLAY BOOKS**";
	cout << "\nPRESS 3 for **CHECK PARTICULAR BOOK**";
	cout << "\nPRESS 4 for **UPDATE BOOK**";
	cout << "\nPRESS 5 for **Buy BOOK**";
	cout<<"\nPRESS 6 for **DELETE Book**";
	cout << "\nPRESS 0 for **EXIT**";
}

void bookshope::add_book()
{
	
	fstream file1;
	int no_copy,b_price;
	string b_name, a_name, b_id;
	cout << "\n\n\t\t\t\tADD BOOKS";
	cout << "\n\nBook ID : ";
	cin >> b_id;
	cout << "\nBook Name : ";
	cin>>b_name;

	cout << "\nAuthor Name : ";
	cin >> a_name;
	cout << "\nNo. of Books : ";
	cin >> no_copy;
    cout<<" \nBook price : ";
    cin>>b_price;

	file1.open("book.txt",ios::out | ios::app);
	file1 << " " << b_id << " "
		<< b_name << " " << a_name
		<< " " << no_copy << " "<<b_price<<"\n";
	file1.close();
}

void bookshope::show_book()
{
	
	fstream file;
	int no_copy,b_price;
	string b_name, b_id, a_name;
	cout << "\n\n\t\t\t\t\tAll BOOKS\n\n";
	cout<<"|------------------------------------------------------------------------|\n";

	
	file.open("book.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		
		cout<<"|Book ID\tBOOK\t\tAuthor\t\tNo.of_Books\tPrice    |\n";
		cout<<"|------------------------------------------------------------------------|\n";

		file >> b_id >> b_name;
		file >> a_name >> no_copy>> b_price;

	
		while (!file.eof()) 
		{

			cout <<"|"<< " " << b_id
				<< "\t\t"<< b_name
				<< "\t\t" << a_name
				<< "\t\t"<<no_copy
                << "\t\t" << b_price<<"      |"
				<< "\n";
				cout<<"|------------------------------------------------------------------------|\n";

			file >> b_id >> b_name;
			file >> a_name >> no_copy>>b_price;
		}

		

		
		file.close();
	}
}

void bookshope::check_book()
{
	
	fstream file;
	int no_copy, count = 0,b_price;
	string b_id, b_name, a_name, b_idd;

	cout << "\n\n\t\t\t\tCheck "
		<< "Particular Book";

	file.open("book.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nBook ID : ";
		cin >> b_idd;
		file >> b_id >> b_name;
		file >> a_name >> no_copy>> b_price;

		while (!file.eof()) {

			if (b_idd == b_id) {

				
				cout << "\n\n\t\t\t\t"
					<< "Check Particular Book";
				cout << "\n\nBook ID : "
					<< b_id;
				cout << "\nName : "
					<< b_name;
				cout << "\nAuthor : "
					<< a_name;
				cout << "\nNo. of Books : "
					<< no_copy;
                cout <<" \nBook price :"<< b_price;
				cout << endl
					<< endl;
				count++;
				break;
			}
			file >> b_id >> b_name;
			file >> a_name >> no_copy>> b_price;
		}
		
		file.close();
		if (count == 0)
			cout << "\n\nBook ID Not"
				<< " Found...";
	}
}

void Update :: buy_book()
{
    
		fstream file, file1;

		int no_copy, no_co, count = 0;
	
		string b_name, b_na, a_name;
	
		string a_na, b_idd, b_id ,b_price;

		cout << "\n\n\t\t\t\tUpdate Book Record";
		file1.open("book1.txt",ios::app | ios::out);
		file.open("book.txt", ios::in);

		if (!file)
		{
			cout << "\n\nFile Opening Error!";
		}
		else 
		{

			cout << "\n\nBook ID : ";
			cin >> b_id;
			file >> b_idd >> b_name;
			file >> a_name >> no_copy>>b_price;

			while (!file.eof()) 
			{
				if (b_id == b_idd) 
				{
                    if(no_copy>=1)
                    {
                      no_copy--;
                      file1 << " " << b_idd << " "
						<< b_name << " "
						<< a_name << " " << no_copy <<" "<<b_price<< "\n\n";
                      cout<<"\nThank you for purchasing the book !!!\n";

                    }
                    else 
                    {
                        cout<<"\nBook is out of stock !!";
						file1 << " " << b_idd << " "
						<< b_name << " "
						<< a_name << " " << no_copy <<" "<<b_price<< "\n\n";
                    }
                  count++;
		    }
				else
				{
					file1 << " " << b_idd
						<< " " << b_name
						<< " " << a_name
						<< " " << no_copy
                    	<< " "<<b_price
						<< "\n\n";
				}
				file >> b_idd >> b_name;
				file >> a_name >> no_copy>>b_price;
			}
			if (count == 0)
			{
				cout << "\n\nBook ID"
					<< " Not Found...";
			}
		}
		cout << endl;
		


		file.close();
		file1.close();
		remove("book.txt");
		rename("book1.txt","book.txt");
}





void Update :: update_book()
	{
		
		fstream file, file1;

		int no_copy=0, no_co=0, count = 0;
	
		string b_name, b_na, a_name;
	
		string a_na, b_idd, b_id ,b_price;

		cout << "\n\n\t\t\t\tUpdate Book Record";
		file1.open("book1.txt",ios::app | ios::out);
		                                                            
		                                        
		file.open("book.txt", ios::in);

		if (!file)
		{
			cout << "\n\nFile Opening Error!";
		}
		else 
		{

			cout << "\n\nBook ID : ";
			cin >> b_id;
			file >> b_idd >> b_name;
			file >> a_name >> no_copy>>b_price;

			while (!file.eof()) 
			{
				if (b_id == b_idd) 
				{
					
					cout << "\t\t\t\t"<< "Update Book Record";
					cout << "\n\nNew Book Name : ";
					cin >> b_na;
					cout << "\nAuthor Name : ";
					cin >> a_na;
					cout << "\nNo. of Books : ";
					cin >> no_co;
                	cout<<"\n New price of book :";
                	cin>>b_price;
					file1 << " " << b_id << " "
						<< b_na << " "
						<< a_na << " " << no_co <<" "<<b_price
						<< "\n\n";
					count++;
				}
				else
				{
					file1 << " " << b_idd
						<< " " << b_name
						<< " " << a_name
						<< " " << no_copy<< " "<<b_price<< "\n\n";
				}
				file >> b_idd >> b_name;
				file >> a_name >> no_copy>>b_price;
			}
			if (count == 0)
			{
				cout << "\n\nBook ID Not Found...";
			}
		}
		cout << "\n";
		


		file.close();
		file1.close();
		remove("book.txt");
		rename("book1.txt","book.txt");
	}


void Update :: del_book()
{
	
	fstream file, file1;
	int no_copy=0, count = 0;
	string b_id, b_idd, b_name, a_name;
	cout << "\n\n\t\t\t\tDelete a Book";


	file1.open("book1.txt",ios::app | ios::out);
	file.open("book.txt",ios::in);

	if (!file)
	{
		cout << "\n\nFile Opening Error...";
	}
	else 
	{

		cout << "\n\nBook ID : ";
		cin >> b_id;
		file >> b_idd >> b_name;
		file >> a_name >> no_copy;
			
		while (!file.eof()) 
		{
				

			if (b_id == b_idd)
			{
				 	
				
				cout << "\n\n\t\t\t\t"<< "Delete a Book";
				
				cout << "\n\nBook is Deleted Successfully...\n\n";
					count++;
					
			}
			else
			{
					
				file1 << b_idd
					<< " " << b_name
					<< " " << a_name
					<< " " << no_copy
					<< "\n\n";
			}
			file >> b_idd >> b_name;
			file >> a_name >> no_copy;
		}
			
			
		if (count == 0)
		{
			cout << "\n\nBook ID Not Found...";
		}
	}
		
	remove("book.txt");
	rename("book1.txt","book.txt");
	file.close();
	file1.close();
}
