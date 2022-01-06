#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <list>
#include <set>
#include <sstream> 
#include <algorithm>

using namespace std;

void writeOutput(string out, char* fileName) {
	// Please write your code here!
	ofstream fStream(fileName); // declare an out-file stream

	fStream << out; //write the string into the open file stream
	fStream.close(); //close the out file stream to release resources
}

string readInput(char* fileName) {
	// Please write your code here!
	ifstream fStream; // declare an in-file stream
	fStream.open(fileName); // open the file stream for reading

	stringstream strStream; // declare a string stream
	strStream << fStream.rdbuf(); //read the file into the file stream
	return strStream.str(); //return the string result of the fileName text
}

// Definition of the struct
struct letter {
	// Please write your code here!
	// You must have a char, an int and a bool in this struct!
	char name; // the letter of the alphabet
	int point; // the point associated with the letter
	bool isVowel; // it is a vowel or consonant
};

// Definition of the Class 
class Word {

private:
	string word;
	int counter;
	int point;

public:
	Word(string word1, int counter1, int point1) //constructor for the class word
	{
		/* Please write your code here! */
		word = word1; //initialize the variable word with the word1
		counter = counter1; //initialize the variable counter with the counter1
		point = point1; //initialize the variable point with the point1
	}
	void setWord(string word1) {/* Please write your code here! */
		word = word1; //initialize the variable word with the word1
	}
	const string getWord() const {/* Please write your code here! */
		return word;
	}
	const int getLength() const {/* Please write your code here! */
		return word.length();
	}
	void setCounter(int counter1) {/* Please write your code here! */
		counter = counter1;
	}
	void setCounterPP() {/* Please write your code here! */
		counter++;
	}
	const int getCounter() const {/* Please write your code here! */
		return counter;
	}
	void setPoint(int point1) {/* Please write your code here! */
		point = point1;
	}
	const int getPoint() const {/* Please write your code here! */
		return point;
	}
};

// Created an array of the letter
letter letters[26];

// Use the letters array and initialise it
void createTable() {
	// Please write your code here!

	letters[0] = { 'A', 10, true };
	letters[1] = { 'B', 21, false };
	letters[2] = { 'C', 7, false };
	letters[3] = { 'D', 2, false };
	letters[4] = { 'E', 19, true };
	letters[5] = { 'F', 18, false };
	letters[6] = { 'G', 4, false };
	letters[7] = { 'H', 8, false };
	letters[8] = { 'I', 6, true };
	letters[9] = { 'J', 11, false };
	letters[10] = { 'K', 14, false };
	letters[11] = { 'L', 3, false };
	letters[12] = { 'M', 9, false };
	letters[13] = { 'N', 22, false };
	letters[14] = { 'O', 1, true };
	letters[15] = { 'P', 23, false };
	letters[16] = { 'Q', 17, false };
	letters[17] = { 'R', 5, false };
	letters[18] = { 'S', 25, false };
	letters[19] = { 'T', 13, false };
	letters[20] = { 'U', 12, true };
	letters[21] = { 'V', 26, false };
	letters[22] = { 'W', 24, false };
	letters[23] = { 'X', 16, false };
	letters[24] = { 'Y', 20, false };
	letters[25] = { 'Z', 15, false };
}

// Calculating points for a word
int calPoints(string str) {
	// Please write your code here!
	int points = 0;
	for (std::string::size_type i = 0; i < str.size(); i++) //using string::size_type guarantees no matter how big that string is, its can hold the value.
	{
		for (int j = 0; j < sizeof(letters); j++) // loop through the array of letter to find the appropiate alphabet
		{
			if (letters[j].name == toupper(str[i])) // if the letters array at position j is equal the char in the string
			{
				points += letters[j].point; // add the points 
				break; // exit the loop and move to the next pointer
			}
		}
	}
	return points; // return total points
}

// Check if a word is palindrome
bool isPalindrome(string str) {
	// Please write your code here!
	int length = str.size(); // get the size or length of the passed variable
	for (std::string::size_type i = 0; i < length; i++) //using string::size_type guarantees no matter how big that string is, its can hold the value.
		if (str[i] != str[length - i - 1])// check if the char is not same as the reverse from the end of the string
			return false; // return false meaning is not a palindrome word

	return true;// is a palindrome word
}

// Implementing Caesar cipher system (only decipher function)
string caesarDecipher(string secret, int key)
{
	// Please write your code here!
	string result = ""; // a variable to store the processed text
	char c; // a character used to store each letter while iterating 

	for (int i = 0; i < secret.length(); i++)
	{
		c = secret[i];
		// Decrypt Uppercase letters 
		if (isupper(secret[i])) {
			result += (char)(((secret[i] - key - 'A' + 26) % 26) + 'A');
		}
		// Decrypt Lowercase letters 
		else {
			result += (char)(((secret[i] - key - 'a' + 26) % 26) + 'a');
		}
	}
	// Return the resulting string 
	return result;
}

// Criterion1
bool criterion1(list<Word> w) {
	// Please write your code here!
	int minWordLength = 0;

	w.sort([](const Word& f, const Word& s) { return f.getLength() < s.getLength(); }); //sort the list in ascending order using the length of the word

	for (std::list<Word>::iterator it = w.begin(); it != w.end(); ++it) // iterate over the list of words  
	{
		int len = it->getLength();

		if (len != 1) {
			if (minWordLength == 0) //if minimum word length hasnt been set then set it
				minWordLength = len;

			if (minWordLength == len) {
				if (it->getPoint() >= 10 && it->getPoint() <= 50) //if the mimimum detected length is within the point range
					return true;
			}
			else
				return false;
		}
	}
	return false;
}

// Criterion2
bool criterion2(list<Word> w) {
	// Please write your code here!
	w.sort([](const Word& f, const Word& s) { return f.getLength() > s.getLength(); }); // sort the list in descending order using the length of the word

	int maxWordLength = w.front().getLength();// get the first word in the list length of word

	for (std::list<Word>::iterator it = w.begin(); it != w.end(); ++it) // iterate over the list of words  
	{
		if (maxWordLength == it->getLength()) {
			if (it->getPoint() >= 200 && it->getPoint() <= 250) //if the max detected length is within the point range
				return true;
		}
		else
			return false;
	}
	return false;
}

// Criterion3
bool criterion3(list<Word> w) {
	// Please write your code here!
	int counter = 0;
	for (std::list<Word>::iterator it = w.begin(); it != w.end(); ++it) // iterate over the list of words  
	{
		if (isPalindrome(it->getWord()))//check if the word is a palindrome word
			counter++;//increase counter if palindrome
		if (counter >= 5)
			return true;
	}
	return false;
}

// Criterion4
bool criterion4(list<Word> w) {
	// Please write your code here!
	int counter = 0;// variable to store occurance of word

	for (std::list<Word>::iterator it = w.begin(); it != w.end(); ++it) // iterate over the list of words  
		counter += it->getCounter(); //increase counter by number of occurance

	if (counter >= 50 && counter <= 100) //check if counter is between 50 and 100
		return true;

	return false;
}

// Criterion5
bool criterion5(list<Word> w) {
	// Please write your code here!
	int totalLetters = 0, totalWords = 0, totalPoints = 0, avgLetters, avgPoints;

	for (std::list<Word>::iterator it = w.begin(); it != w.end(); ++it) {
		totalLetters += it->getLength() * it->getCounter();// compute total letters by multiple occurance by word length
		totalPoints += it->getPoint() * it->getCounter();// compute total points by multiple occurance by word points
		totalWords += it->getCounter(); // compute total words by summing the occurances
	}

	avgLetters = totalLetters / totalWords;//get the average of the letters 
	avgPoints = totalPoints / totalWords; // get the average points

	//check if the average number of letters is between 4 and 8 and average point is between 20 and 60
	if ((avgLetters >= 4 && avgLetters <= 8) && (avgPoints >= 20 && avgPoints <= 60))
		return true;
	return false;
}

// Criterion6
bool criterion6(list<Word> w) {
	// Please write your code here!

	for (std::list<Word>::iterator it = w.begin(); it != w.end(); ++it) {
		string str = it->getWord();
		int counter = 0;
		for (std::string::size_type i = 0; i < it->getLength(); i++) //using string::size_type guarantees no matter how big that string is, its can hold the value.
		{
			for (int j = 0; j < sizeof(letters); j++) // loop through the array of letter to find the appropiate alphabet
			{
				if (letters[j].name == toupper(str[i])) // if the letters array at position j is equal the char in the string
				{
					if (letters[j].isVowel)
						counter++; // increase the counter 
					break; // exit the loop and move to the next pointer
				}
			}
			if (counter > 4) //if word of type V is more than 4 then return false
				return false;
		}
	}
	return true;
}
//used for creating list of words
list<Word> createList(string str) {
	str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
	list<Word> result; //declare a list of word variable
	istringstream iss{ str }; // create a string stream from the input sentence
	bool exists = false;
	string s = "";

	while (getline(iss, s, ' ')) //loop through a stream of the string 
	{
		exists = false; // flag exists as false
		for (std::list<Word>::iterator it = result.begin(); it != result.end(); ++it) // iterate over the list of words to check for duplicate
		{
			if (s == it->getWord()) // check if the word already exists in the list
			{
				exists = true; //flag exists as true
				it->setCounterPP(); // increase the counter
				break;
			}
		}
		if (!exists)
			result.push_back(Word(s, 1, calPoints(s))); //add new words to the list
	}
	return result;
}

//method to get words at a specified position. if position specified is -1 then its get the last word
string getWordAt(string str, int position)
{
	string result;

	if (position == -1)// check if the request is to get the last word
	{
		istringstream({ str.rbegin(), str.rend() }) >> result; // read the begin to end in reverse 
		return { result.rbegin(), result.rend() }; // return the word
	}

	istringstream iss;
	iss.str(str);
	for (int n = 0; n < position; n++) // loop to the provided position and read the stream
		iss >> result; //write the string stream to the result variable

	return result;
}

//convert a boolean to text pass or fail
string boolToString(bool value) // method to write the result of the criteria as pass or fail
{
	if (value)
		return "pass"; // return pass if the value is true

	return"fail"; //return fail if false
}

//function for solving task 1
string task1(list<Word> w) {
	return boolToString(criterion1(w)) + "," +
		boolToString(criterion2(w)) + "," +
		boolToString(criterion3(w)) + "," +
		boolToString(criterion4(w)) + "," +
		boolToString(criterion5(w)) + "," +
		boolToString(criterion6(w));
}

//function for solving task 2
string task2(list<Word> w) {
	string shortest, longest, lowestPoint, highestPoint, lFreq, mFreq;

	// sort the list in ascending order using the length of the word and then use the word
	w.sort([](const Word& f, const Word& s) { return f.getLength() < s.getLength() || f.getLength() == s.getLength() && f.getWord() < s.getWord(); });
	shortest = w.front().getWord(); //get the first word length in the list  of word
	longest = w.back().getWord();//get the last word length in the list of word

	 // sort the list in ascending order using the occurance of the word and then use the word point 
	w.sort([](const Word& f, const Word& s) { return f.getCounter() < s.getCounter() || f.getCounter() == s.getCounter() && f.getPoint() < s.getPoint(); });// sort the list in ascending order using the counter
	lFreq = w.front().getWord(); //get the 1st counter value
	mFreq = w.back().getWord();//get the last counter value

	// sort the list in ascending order using the word point 
	w.sort([](const Word& f, const Word& s) { return (f.getPoint() < s.getPoint()); });
	lowestPoint = w.front().getWord();
	highestPoint = w.back().getWord();

	return shortest + "," + longest + "," + lowestPoint + "," + highestPoint + "," + lFreq + "," + mFreq;
}

//function for solving task 3
string task3(list<Word> w) {
	string result;

	// sort the list in ascending order using the occurance, then by the point then the number of letters in the word
	w.sort([](const Word& f, const Word& s)
		{
			if (f.getCounter() != s.getCounter())
				return f.getCounter() < s.getCounter();

			if (f.getPoint() != s.getPoint())
				return f.getPoint() < s.getPoint();

			if (f.getLength() != s.getLength())
				return f.getLength() < s.getLength();

			return f.getCounter() < s.getCounter();
		});

	for (std::list<Word>::iterator it = w.begin(); it != w.end(); ++it) // iterate over the list of words  
		result += to_string(it->getCounter()) + it->getWord() + ","; //append each iteration to the result variable

	result = result.erase(result.find_last_not_of(',') + 1); //use the erase method to trim the last comma
	return result;
}

//function for solving task 4
string task4(string str)
{
	list<Word> w = createList(str); // create list of words to used for the encrypted secret

	string sName = getWordAt(str, 10); // student name which is the 10th word in the essay 
	int points = calPoints(sName); // calculate the points for the name
	int key = points % 26; // get the decipher key
	int counter = 0;
	string encryptedSecret;

	for (std::list<Word>::iterator it = w.begin(); it != w.end(); ++it) // iterate over the list of words  
	{
		if (it->getPoint() >= 90 && it->getPoint() <= 110) {
			counter++;
			if (counter == 2) {
				encryptedSecret = it->getWord();// get the encrypted text
				break;
			}
		}
	}
	if (counter < 2)
		encryptedSecret = getWordAt(str, -1);//get last word as the encrypted text

	string decryptedSecret = caesarDecipher(encryptedSecret, key); // decrypt the encrypted text using the decipher key

	return  sName + "," + to_string(key) + "," + encryptedSecret + "," + decryptedSecret;
}

//function for solving task 5
string task5(list<Word> w) {
	int median, size; //integer variable for storing median and size of list
	bool isEvenlySized = false; // a boolean variable to store if the list is evenly size
	string result;
	size = w.size(); //store the size in the variable

	if (size % 2 == 0) //check if the number of words in the list is even
		isEvenlySized = true;

	median = size / 2; //get the middle point by dividing by 2

	// sort the list in ascending order using the word point 
	w.sort([](const Word& f, const Word& s) { return (f.getPoint() < s.getPoint()); });

	auto l_front = w.begin(); // declare a variable for the word list and set the starting to the begining of the list
	if (isEvenlySized) {
		std::advance(l_front, median - 1); //advance to the median -1 because list of words are even 
		result = l_front->getWord();

		std::advance(l_front, 1); //advance a step forward to get the next record
		result += l_front->getWord();
	}
	else
	{
		std::advance(l_front, median); //advance to the middle
		result = l_front->getWord();
	}

	return result;
}