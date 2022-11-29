#include <fstream>
#include <iostream>
#include<conio.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;

void control_panel();
void add_book();
void show_book();

void control_panel()
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

void add_book()
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
	file.open("D://book.txt",
			ios::out | ios::app);
	file<< b_id << "\n"<< b_names << "\n" << a_name<< "\n" << no_copy<<"\n";
	file.close();
}

void show_book()
{
	system("cls");
	fstream file;
	int no_copy;
	string b_names, b_id, a_name;
	cout << "\n\n\t\t\t\t\tAll BOOKS";

	// Open the file in input mode
	file.open("D://book.txt", ios::in);
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


int main()
{
	// Function Call


	return 0;
}
