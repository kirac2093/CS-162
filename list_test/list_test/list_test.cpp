/* ===============================================
Name: list_test.cpp
Code: Kira Corbett
Date: 5/02/2017
Desc: reads and processes strings from a file
using the list class.
=============================================== */

//preprocessor directives
#include <iostream>
#include <fstream>
#include <string>

//header files
#include "list.h"

using namespace std;

const int MAX_STRING = 200;

//function prototypes
bool controlChar(const string& data, List& list1, char stringCommand);

int main()
{
	List list1;

	ifstream inputStream;
	string filename = "listdata.txt";

	char ch;
	char itemsInList[MAX_STRING] = {};
	char listCommand = ' ';

	string data;

	//opens the file
	//if the file open is unsuccessful, error message is displayed
	inputStream.open("listdata.txt");

	if (!inputStream)
	{
		cout << "File " << filename << " could not be opened." << endl;
		cout << "Program terminated!" << endl;
		return -1;
	}

	//read and processes each line of the file
	while (inputStream >> ch)
	{
		//if character valid, get the remaining line
		getline(inputStream, data);

		//call controlChar() to evaluate what is done to the list items
		controlChar(data, list1, ch);
	}

	inputStream.close();

	return 0;
}

////reads single character
//inputStream.get(ch);
//cout << '\n' << "Read Character:" << " " << ch << endl;

////reads line after first character
//inputStream.getline(itemsInList, MAX_STRING);
//cout << "Read Remaining Line:" << data << endl;

////reads line of data in txt file
//getline(inputStream, data);
//cout << "getline() example: " << data << endl;

/* =============================================================
Name: checkChar
Desc: checks character for A, R, F, or P and executes command(s)
Args: data (string) - input data to write list
list1 (class) - includes class List and member list1
stringCommand (char) - char command for A, R, F, or P
Retn: bool
============================================================== */
bool controlChar(const string& data, List& list1, char theCommand)
{
	switch (theCommand)
	{
		//add
	case 'A':
		if (list1.insert(data))
		{
			cout << "Added:\t" << data << endl;
		}
		else
		{
			cout << "Add: Failed!\t" << data << " did not add to the list." << endl;
		}
		break;
		//remove
	case 'R':
		if (list1.remove(data))
		{
			cout << "Remove Succeeded:\t" << data << endl;
		}
		else
		{
			cout << "Remove Failed:\t" << data << endl;
		}
		break;
		//find
	case 'F':
		if (list1.inList(data) == true)
		{
			cout << "Find Succeeded:\t" << data << endl;
		}
		else
		{
			cout << "Find: Failed!\t" << data << " is not in the list." << endl;
		}
		break;
		//print
	case 'P':
		cout << "Print: ";
		list1.printList();
		break;
		//all other cases
	default:
		cout << "Error: Line " << "[" << theCommand << "] " << " - invalid action: " << data << endl;
		return false;
		break;
	}
	return true;
}