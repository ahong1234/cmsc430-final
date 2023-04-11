// CMSC 430
// Dr. Duane J. Jarc
// Alex Hong 
// CMSC 430 Project 2
// Due : 04/11/23
// This file contains the bodies of the functions that produces the compilation
// listing

#include <cstdio>
#include <string>
#include <queue>
using namespace std;

#include "listing.h"

static int lineNumber;
static string error = "";
static int totalErrors = 0;
static queue<string> myQueue; // create a queue to hold multiple errors per line
static int lexErrs = 0; // count for total number of lexical errors
static int synErrs = 0;
static int semErrs = 0;

static void displayErrors();

void firstLine()
{
	lineNumber = 1;
	printf("\n%4d  ",lineNumber);
}

void nextLine()
{
	displayErrors();
	lineNumber++;
	printf("%4d  ",lineNumber);
}

int lastLine() 
{
	printf("\r");
	displayErrors();
	if (totalErrors == 0) 
	{
		// display success message with total number of errors
		printf("Compiled Successfully. Total Errors: %d\n", totalErrors);
	} 
	// display the tally of found errors
	else 
	{
		printf("Lexical Errors: %d    \n", lexErrs);
		printf("Syntax Errors: %d    \n", synErrs);
		printf("Semantic Errors: %d    \n", semErrs);
	}
	return totalErrors;
}
    
void appendError(ErrorCategories errorCategory, string message) 
{
	string messages[] = { "Lexical Error, Invalid Character ", "",
		"Semantic Error, ", "Semantic Error, Duplicate Identifier: ",
		"Semantic Error, Undeclared " };

	// increment the error counters depending on the error category
	if (errorCategory == 0) 
	{
		error = messages[errorCategory] + message;
		lexErrs++;
	}
	else if (errorCategory == 1) 
	{
		error = messages[errorCategory] + message;
		synErrs++;
	}
	else 
	{
		error = messages[errorCategory] + message;
		semErrs++;
	}
	myQueue.push(error); // add the error string to myQueue
	totalErrors++; 
}

void displayErrors() 
{
	while (!myQueue.empty()) {  // show all the errors stored in the queue for one line
		printf("%s\n", myQueue.front().c_str());
		myQueue.pop(); // clear the queue for next line
	}
	
}
