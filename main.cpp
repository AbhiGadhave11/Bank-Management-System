#include <fstream>
#include <iostream>
#include<bits/stdc++.h>
#include "Header.h"

using namespace MYNAMESPACE;
using namespace std;

int main()
{
	int choice;
	char x;
	Update uobj;

	while (1)
	{

		uobj.control_panel();
		cout << "\n\nEnter your choice : ";
		cin >> choice;
		switch (choice)
		{

			case 1:
			{
				do
				{

					uobj.add_book();
					cout << "\n\nWant to add"
						<< " another book? "
							"(y/n) : ";
					cin >> x;
				} while (x == 'y');
				break;
			}

			case 2:
			{
				uobj.show_book();
				break;
			}

			case 3:
			{
				uobj.check_book();
				break;
			}

			case 4:
			{
				uobj.update_book();
				break;
			}

			case 5:
			{
				uobj.buy_book();
				break;
			}

			case 6:
			{
				uobj.del_book();

				break;
			}

			case 0 :
			{
				exit(0);
				break;
			}

			default:
			{
				cout << "\n\nINVALID CHOICE\n";
			}
		}
	}

	return 0;
}
