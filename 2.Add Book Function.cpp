#include <fstream>
#include <iostream>
#include<conio.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;

void control_panel();
void add_book();

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

int main()
{
	// Function Call


	return 0;
}

