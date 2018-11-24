#include <iostream>
#include "Bestseller.h"

using namespace std;

void Bestseller::lowercaseString(string& str)
{
	// Iterates through all characters in the string and assigns the index to their lowercase variant
	for (unsigned int i = 0; i < str.length(); i++)
	{
		str.at(i) = tolower(str.at(i));
	}
}

bool Bestseller::titleMatches(string& search)
{
	return titleLower == search || titleLower.find(search) != string::npos;
}

bool Bestseller::authorMatches(string& search)
{
	return authorLower == search || authorLower.find(search) != string::npos;
}

bool Bestseller::monthYearMatches(int monthSearch, int yearSearch)
{
	return month == monthSearch && year == yearSearch;
}

bool Bestseller::inDateRange(int year1, int year2)
{
	return year >= year1 && year <= year2;
}

void Bestseller::outputBook()
{
	cout << "  " << title << ", in " << category << ", on " << date << " by " << author << " with " << publisher << endl;
}

void Bestseller::setTitle(string& newTitle)
{
	title = newTitle;
	titleLower = title;
	lowercaseString(titleLower);
}

void Bestseller::setAuthor(string& newAuthor)
{
	author = newAuthor;
	authorLower = author;
	lowercaseString(authorLower);
}

void Bestseller::setPublisher(string& newPublisher)
{
	publisher = newPublisher;
}

void Bestseller::setDate(string& newDate)
{
	date = newDate;

	month = stoi(date.substr(0, date.find('/')));
	year = stoi(date.substr(date.rfind('/') + 1, date.length()));
}

void Bestseller::setCategory(string& newCategory)
{
	category = newCategory;
}
