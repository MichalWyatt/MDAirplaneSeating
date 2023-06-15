// MDAirplaneSeating.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<iomanip>

using namespace std;

void showMenu(int& mainMenuChoice);
//void seatAssignment(char& classType, int& row, char& column);
void seatAssignment(char[][6]);
void printOutline(char seatArrangement[][6], int row, char column);
void displaySeatingChart(char array[][6]);

//declare variable globally
const int columns = 6, rows = 13;
char classType;
int getRow;
int getColumn;
int seatChoice;
bool validInput;
int seats[rows][columns];

int main()
{
	//variables
	int mainMenuChoice;
	//char classType;
	//int row;
	char seats[13][6] = { '*' };
	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 6; j++)
			seats[i][j] = '*';

	showMenu(mainMenuChoice);

	while (mainMenuChoice != 2) //loop to book or exit program
	{

		switch (mainMenuChoice)
		{
		case 1:
			//seatAssignment(classType, row, column, seats);
			seatAssignment(seats);
			break;
		case 2:
			return 0;
		}
		showMenu(mainMenuChoice);
	} // end while   
	system("PAUSE");
	return 0;
}

void showMenu(int& menuChoice) {
	cout << "Aimless Airways \n" << endl; //Airline name
	cout << "1. Purchase Tickets \n " << endl;
	cout << "2. Exit \n" << endl;
	cin >> menuChoice;
}

//void seatAssignment(char& classType, int& row, char& column, char array[][6])
void seatAssignment(char array[][6])
{
	int classType;
	int row;
	char column;
	displaySeatingChart(array);
	cout << "The airplane has 13 rows of seats, and each row has 6 seats." << endl;

	cout << "What class do you prefer?\n"
		<< "1. First class \n"
		<< "2. Business class\n"
		<< "3. Economy" << endl;

	cin >> classType;
	//classType = static_cast<char>(toupper(classType));


	while (classType != 1 && classType != 2 && classType != 3)
	{
		cout << "Invalid entry." << endl;
		cout << "Enter class type - 1 or 2 or 3\n"
			<< "1. First class \n"
			<< "2. Business class\n"
			<< "3. Economy class" << endl;
		cin >> classType;
		//classType = static_cast<char>(toupper(classType));
	}
	
	switch (classType)
	{
	case 1:
		cout << "Rows 1 and 2 are first class\n";
		break;
	case 2:
		cout << "Rows 3 - 8 are business class\n";
		break;
	case 3:
		cout << "Rows 9 - 13 are Economy" << endl;
		break;
	}// end switch

	cout << "Please select row (1-13): " << endl;
	cin >> row;

	cout << "Please select column(A-F) \n "
		 << "(A and F are window seats -- C and D are isle seats.):" << endl;
	cin >> column;
	column = static_cast<char>(toupper(column));
	int i = 0;
	if (column == 'A')
		i = 0;
	else if (column == 'B')
		i = 1;
	else if (column == 'C')
		i = 2;
	else if (column == 'D')
		i = 3;
	else if (column == 'E')
		i = 4;
	else if (column == 'F')
		i = 5;

	array[row-1][i] = 'X';

	displaySeatingChart(array);
}


void printOutline(char seatArrangement[][6], int row, char column)
{
	
	int i, x;

	cout << "* - Available " << endl;
	cout << "X - Occupied " << endl;
	cout << setw(12) << "A" << setw(6) << "B" << setw(6) << "C"
		<< setw(6) << "D" << setw(6) << "E" << setw(6) << "F" << endl;

	for (i = 0; i < 13; i++)
	{
		cout << left << setw(3) << "Row " << setw(2) << i + 1;

		for (x = 0; x < 6; x++)
		{
			if (i == row - 1 && x == static_cast<int>(column) - 78)
				cout << right << setw(6) << "X";
			else
				cout << right << setw(6) << "*";

		}
		cout << endl;
	}
}

void displaySeatingChart(char array[][6])
{
	cout << " \t" << "A  " << "B  " << "C  " << "D  " << "E  " << "F  " << endl;
	for (int i = 0; i < 13; i++)
	{
		cout << "Row " << i + 1 << "\t";
		for (int j = 0; j < 6; j++)
		{
			cout << array[i][j] << "  ";
		}
		cout << endl;
	}
}



