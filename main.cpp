#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Bestseller.h"
using namespace std;

class bestseller;

void readLine(ifstream&, string&, char);

void loadBooks(ifstream&, vector<Bestseller>&);

void yearRange(vector<Bestseller>&);

void monthYear(vector<Bestseller>&);

void searchAuthor(vector<Bestseller>&);

void searchTitle(vector<Bestseller>&);

void userMenu(vector<Bestseller>&);

int main()
{
	// Prepare to load bestseller information from the file
	vector<Bestseller> books;
	ifstream input("bestsellers.txt");

	// Load the bestsellers into memory and display the menu
	loadBooks(input, books);
	userMenu(books);

	return 0;
}

// Reads a line from the given input stream to the given string, stopping at the given delimiter and stripping containing whitespace
void readLine(ifstream& in, string& to, char delimiter)
{
	getline(in, to, delimiter);
	// Removes preceding whitespace
	while (isspace(to.at(0)))
	{
		to = to.substr(1, to.length());
	}
	// Removes following whitespace
	while (isspace(to.at(to.length() - 1)))
	{
		to = to.substr(0, to.length() - 1);
	}
}

// Loads a list of bestsellers from a given input into a provided vector of bestsellers
void loadBooks(ifstream& input, vector<Bestseller>& books)
{
	// While the input has more data
	while (input.good())
	{
		Bestseller book;

		string temp;

		// Load and assign the book's title
		readLine(input, temp, '\t');
		book.setTitle(temp);

		// Load and assign the book's author
		readLine(input, temp, '\t');
		book.setAuthor(temp);

		// Load and assign the book's publisher
		readLine(input, temp, '\t');
		book.setPublisher(temp);

		// Load and assign the book's date added to the list
		readLine(input, temp, '\t');
		book.setDate(temp);

		// Load and assign the book's category
		readLine(input, temp, '\n');
		book.setCategory(temp);

		// Adds the book to the vector
		books.push_back(book);
	}
}

// Displays a menu of user options and handles their selection, repeating until they choose to quit
void userMenu(vector<Bestseller>& loaded)
{
	char choice;
	do
	{
		cout << "What would you like to do?" << endl;
		cout << "1: Look up year range" << endl;
		cout << "2: Look up month/year" << endl;
		cout << "3: Search for author" << endl;
		cout << "4: Search for title" << endl;
		cout << "Q: Quit" << endl;

		cin >> choice;

		switch(choice)
		{
		case '1':
			yearRange(loaded);
			break;
		case '2':
			monthYear(loaded);
			break;
		case '3':
			searchAuthor(loaded);
			break;
		case '4':
			searchTitle(loaded);
			break;
		default:
			break;
		}
	}
	while (tolower(choice) != 'q');
}

// Searches for and outputs all books in a user-provided year range
void yearRange(vector<Bestseller>& books)
{
	cout << "Enter beginning year: ";
	int yearStart;
	cin >> yearStart;
	cout << "Enter ending year: ";
	int yearEnd;
	cin >> yearEnd;

	int found = 0;
	cout << "All Titles between " << yearStart << " and " << yearEnd << ":" << endl;

	for (int i = books.size() - 1; i >= 0; i--)
	{
		if (books.at(i).inDateRange(yearStart, yearEnd))
		{
			found++;
			books.at(i).outputBook();
		}
	}

	// If no books were found...
	if (found == 0)
	{
		cout << "No titles found in that range!" << endl;
	}
	cout << endl;
}

// Searches for and outputs all books in a user-provided month and year
void monthYear(vector<Bestseller>& books)
{
	int month;
	// Loops until a valid (1-12) month number is provided
	do
	{
		cout << "Enter month (as a number, 1-12): ";
		cin >> month;
	}
	while (month < 1 || month > 12);

	cout << "Enter year: ";
	int year;
	cin >> year;

	int found = 0;
	cout << "All Titles in month " << month << " of " << year << ":" << endl;

	for (int i = books.size() - 1; i >= 0; i--)
	{
		if (books.at(i).monthYearMatches(month, year))
		{
			found++;
			books.at(i).outputBook();
		}
	}

	// If no books were found...
	if (found == 0)
	{
		cout << "No titles found in that month and year!" << endl;
	}
	cout << endl;
}

// Searches for and outputs all books whose author is or contains a user-provided string (case insensitive)
void searchAuthor(vector<Bestseller>& books)
{
	cout << "Enter an author's name (or part of a name):" << endl;
	string name;
	// Handle mixing of stream extraction operator and getline
	ws(cin);
	getline(cin, name);
	// Trim whitespace from user entry
	while (isspace(name.at(name.length() - 1)))
	{
		name = name.substr(0, name.length() - 1);
	}

	int found = 0;
	cout << "All Titles with authors matching '" << name << "':" << endl;

	// Search based on the input as lowercase to insure case insensitivity
	Bestseller::lowercaseString(name);

	for (int i = books.size() - 1; i >= 0; i--)
	{
		if (books.at(i).authorMatches(name))
		{
			found++;
			books.at(i).outputBook();
		}
	}

	// If no books were found...
	if (found == 0)
	{
		cout << "No titles found with matching authors!" << endl;
	}
}

// Searches for and outputs all books whose title is or contains a user-provided string (case insensitive)
void searchTitle(vector<Bestseller>& books)
{
	cout << "Enter a title (or part of a title):" << endl;
	string name;
	// Handle mixing of stream extraction operator and getline
	ws(cin);
	getline(cin, name);
	// Trim whitespace from user entry
	while (isspace(name.at(name.length() - 1)))
	{
		name = name.substr(0, name.length() - 1);
	}

	int found = 0;
	cout << "All Titles matching '" << name << "':" << endl;

	// Search based on the input as lowercase to insure case insensitivity
	Bestseller::lowercaseString(name);

	for (int i = books.size() - 1; i >= 0; i--)
	{
		if (books.at(i).titleMatches(name))
		{
			found++;
			books.at(i).outputBook();
		}
	}

	// If no books were found...
	if (found == 0)
	{
		cout << "No matching titles found!" << endl;
	}
}
