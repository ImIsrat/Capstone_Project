
#include <fstream>
#include <iostream>
#include<conio.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;

// Bookshop Class
class bookshope {
public:
	void control_panel();
	void add_book();
	void show_book();
	void check_book();
	void update_book();
	void del_book();
};

// Function to display the menus
void bookshope::control_panel()
{
	system("cls");
	cout << "\n\n\t\t\t\tCONTROL PANEL";
	cout << "\n\n1. ADD BOOK";
	cout << "\n2. DISPLAY BOOKS";
	cout << "\n3. CHECK PARTICULAR BOOK";
	cout << "\n4. UPDATE BOOK";
	cout << "\n5. DELETE BOOK";
	cout << "\n6. EXIT";
}

// Function to add book
void bookshope::add_book()
{
	system("cls");
	fstream file;
	int no_copy;
	string b_names, a_name, b_id;
	cout << "\n\n\t\t\t\tADD BOOKS";
	cout << "\n\nBook ID(Enter only numerals) : ";
	cin >> b_id;
	cout << "\nBook Name : ";
	cin.ignore();
	getline(cin,b_names);
	cout << "\nAuthor Name : ";
	getline(cin,a_name);
	cout << "\nNo. of Books(Enter only numerals) : ";
	cin >> no_copy;

	// Open file in append or
	// output mode
	file.open("D:/names.txt",
			ios::out | ios::app);
	file<< b_id << "\n"<< b_names << "\n" << a_name<< "\n" << no_copy<<"\n";
	file.close();
}

// Function to display book
void bookshope::show_book()
{
	system("cls");
	fstream file;
	int no_copy;
	string b_names, b_id, a_name;
	cout << "\n\n\t\t\t\t\tAll BOOKS";

	// Open the file in input mode
	file.open("D://names.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\n\nBook ID\t\tBook"<< "\t\t\tAuthor\t\t\tNo. of ""Books\n\n";


		// Till end of file is reached
		string tp ;
		int count=0;
		while (getline(file,tp)) {

          cout << tp << "\t\t";
          count++;
          if(count==4){
            cout << endl;
            count=0;
            }
		}




		// Close the file
		file.close();
		getch();
	}
}

// Function to check the book
void bookshope::check_book()
{
	system("cls");
	fstream file;
	int count = 0;
	string b_idd;

	cout << "\n\n\t\t\t\tCheck "
		<< "Particular Book";

	// Open the file in input mode
	file.open("D://names.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nBook ID : ";
		cin >> b_idd;
		string tp ;
		int count=0;
		while (getline(file,tp)) {

			if (b_idd == tp) {

				system("cls");
				cout << "\n\n\t\t\t\t"<< "Check Particular Book";
				cout << "\n\nBook ID : "<< tp;
				getline(file,tp);
				cout << "\nName : "<< tp;
				getline(file,tp);
				cout << "\nAuthor : "<< tp;
				getline(file,tp);
				cout << "\nNo. of Books : "<< tp;
				cout << endl<< endl;
				count++;
				break;
			}

		}
		if (count == 0)
			cout << "\n\nBook ID Not Found..."<<endl;
		getch();
		file.close();

	}
}

// Function to update the book
void bookshope::update_book()
{
	system("cls");
	fstream file, file1;
	int no_copy, no_co, count = 0;
	string b_name, b_na, a_name;
	string a_na, b_idd, b_id;

	cout << "\n\n\t\t\t\tUpdate Book Record";
	file1.open("D://names1.txt",ios::app | ios::out);
	file.open("D://names.txt",ios::in);

	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nBook ID : ";
		cin >> b_id;

		while (getline(file,b_idd)){
			if (b_id == b_idd) {

				system("cls");
				cout << "\t\t\t\t"
					<< "Update Book Record";
				cout << "\n\nNew Book Name : ";
				cin.ignore();
				getline(cin,b_na);
				cout << "\nAuthor Name : ";
				getline(cin,a_na);
				cout << "\nNo. of Books : ";
				cin >> no_co;
				file1<< b_id << "\n"<< b_na << "\n"<< a_na << "\n" << no_co<< "\n";
				count++;
				getline(file,b_idd);
				getline(file,b_idd);
				getline(file,b_idd);
			}
			else
				file1<< b_idd<<"\n";

		}
		if (count == 0)
			cout << "\n\nBook ID"
				<< " Not Found...";
	}
	cout << endl;
	getch();

	// Close the files
	file.close();
	file1.close();
	remove("D://names.txt");
	rename("D://names1.txt","D://names.txt");

}
// Function to delete book
void bookshope::del_book()
{
	system("cls");
	fstream file, file1;
	string b_id;
	string tp;
	int count = 0;
	cout << "\n\n\t\t\t\tDelete a Book";

	// Append file in output mode
	file1.open("D://names1.txt",
			ios::app | ios::out);
	file.open("D://names.txt",
			ios::in);

	if (!file)
		cout << "\n\nFile Opening Error...";
	else {

		cout << "\n\nBook ID : ";
		cin >> b_id;
		while (getline(file,tp)) {

			if (b_id == tp) {

				getline(file,tp);
				getline(file,tp);
				getline(file,tp);
				count++;
			}
			else
				file1 <<tp<<"\n";

		}
		if (count == 0)
			cout << "\n\nBook ID Not Found...";
	}
	cout << endl;
	getch();

	// Close the file
	file.close();
	file1.close();
	remove("D://names.txt");
	rename("D://names1.txt","D://names.txt");

}

// Function for book shop record
void bookShopRecord()
{
	int choice;
	char x;
	bookshope b;

	while (1) {

		b.control_panel();
		cout << "\n\nEnter your choice : ";
		cin >> choice;
		switch (choice) {

		case 1:
			do {

				b.add_book();
				cout << "\n\nWant to add"
					<< " another book? "
						"(y/n) : ";
				cin >> x;
			} while (x == 'y');
			break;

		case 2:
			b.show_book();
			break;

		case 3:
			b.check_book();
			break;
		case 4:
			b.update_book();
			break;

		case 5:
			b.del_book();
			break;

		case 6:
			exit(0);
			break;

		default:
			cout << "\n\nINVALID CHOICE\n";
		}
	}
}

// Driver Code
int main()
{
	// Function Call
	bookShopRecord();

	return 0;
}
