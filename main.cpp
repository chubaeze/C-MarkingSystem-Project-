#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <list>
#include <set>
#include <sstream> 
#include <algorithm>
#include "definitions.h"

using namespace std;

int main(int argc, char* argv[])
{
	// Initialisation
	createTable();
	string text, result;

	char* inputFile = argv[1];
	char* outputFile = argv[2];

	// Read the input
	text=readInput(inputFile);

	// Split the input into words and put it into a list of elements of class Word! 
	list<Word> v = createList(text);

	// Task 1:
	// 1st criterion
	// 2nd criterion
	// 3rd criterion
	// 4th criterion
	// 5th criterion
	// 6th criterion
	result = task1(v);

	// Add the seperator
	// At this point you must add ';' as the seperator to your output 
	result += ";";

	// Task 2:
	// Shortest and longest
	// Lowest point and highest point
	// Less frequent and most frequent
	result += task2(v);

	// Add the seperator
	// At this point you must add ';' as the seperator to your output 
	result += ";";

	// Task 3: 
	// Numebr of appearance for each word
	result += task3(v);

	// Add the seperator
	// At this point you must add ';' as the seperator to your output 
	result += ";";

	// Task 4:
	// Student name, key and the secret
	result += task4(text);

	// Add the seperator
	// At this point you must add ';' as the seperator to your output 
	result += ";";

	// Task 5:
	// The one in the middle
	result += task5(v);

	// Write input in the file
	writeOutput(result, outputFile);

	return 0;
}