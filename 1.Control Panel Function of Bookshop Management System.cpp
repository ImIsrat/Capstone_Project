// C++ program to illustrate Bookshop Management System
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;



	void control_panel();



// Function to display the menu
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

int main()
{
	// Function Call
	control_panel();

	return 0;
}
