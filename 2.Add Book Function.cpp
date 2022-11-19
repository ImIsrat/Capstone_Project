
// C++ program to illustrate bookshop
// management system using File Handling
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void add_book();


void add_book()
{
	system("cls");
	fstream file;
	int no_copy;
	string b_names, a_name, b_id;
	cout << "\n\n\t\t\t\tADD BOOKS";
	cout << "\n\nBook ID : ";
	cin >> b_id;
	cout << "\nBook Name : ";
	cin >> b_names;
	cout << "\nAuthor Name : ";
	cin >> a_name;
	cout << "\nNo. of Books : ";
	cin >> no_copy;

	// Open file in append or
	// output mode
	file.open("book.txt",
			ios::out | ios::app);
	file << " " << b_id << " "
		<< b_names << " " << a_name
		<< " " << no_copy << "\n";
	file.close();
}

int main()
{
	// Function Call
	add_book();

	return 0;
}
