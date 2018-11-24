#ifndef BESTSELLER_H_
#define BESTSELLER_H_

#include <string>
using namespace std;

/**
 * Data class containing information about the books in the form of data members
 * and functions for implementing the different user options as instance methods
 */
class Bestseller
{
private:
	string title;
	string titleLower;
	string author;
	string authorLower;
	string publisher;
	string date;
	int month;
	int year;
	string category;
public:
	// Converts the given string to lowercase
	static void lowercaseString(string& str);

	// Checks if the title of this bestseller is or contains a given string (case insensitive)
	bool titleMatches(string& search);

	// Checks if the author of this bestseller is or contains a given string (case insensitive)
	bool authorMatches(string& search);

	// Checks if the month and year this bestseller was added to the list matches a given input
	bool monthYearMatches(int monthSearch, int yearSearch);

	// Checks if the year this bestseller was added to the list falls within a given date range
	bool inDateRange(int year1, int year2);

	// Outputs the state of this book to the console
	void outputBook();

	// Sets the title of this book and also provides the lowercase title
	void setTitle(string& newTitle);

	// Sets the author of this book and also provides the lowercase author
	void setAuthor(string& newAuthor);

	// Sets the publisher of this book
	void setPublisher(string& newPublisher);

	// Sets the date this book was added to the bestseller list
	void setDate(string& newDate);

	// Sets the category of this book (Fiction / Non Fiction)
	void setCategory(string& newCategory);
};

#endif /* BESTSELLER_H_ */
