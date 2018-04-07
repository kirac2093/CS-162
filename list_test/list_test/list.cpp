/* ===============================================
Name: list.cpp
Code: Kira Corbett
Date: 4/20/2017
Desc: class definitions for list.h
=============================================== */

//preprocessor directives
#include <iostream>
#include <string>

//header files
#include "list.h"

using namespace std;

List::List()
{
	//clear array prior to starting (set everything to NULL)
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		items[i] = " ";
	}

	totalItems = 0;
}


bool List::insert(const string& data)
{

	//verifies that string is not empty, not in the list, and not full
	if (data.empty() == true || inList(data) == true || full() == true)
	{
		return false;
	}
	else
	{
		//increment totalItems in the array; those items equal the variable data
		items[totalItems++] = data;
		return true;
	}
}


//process array until totalItems
bool List::empty() const
{
	//runs through loop to verify array is empty
	for (int i = 0; i < totalItems; i++)
	{
		if (items[i].empty())
		{
			return true;
		}
	}
	return false;
}

//identifies whether the string is full or not
bool List::full() const
{
	if (totalItems == MAX_ITEMS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool List::inList(const string& data) const
{
	//runs through loop to determine if string is in the list
	for (int i = 0; i < totalItems; i++)
	{
		if (items[i] == data)
		{
			return true;
		}
	}
	return false;
}

bool List::remove(const string& data)
{
	//returns false if variable empty
	if (data.empty())
		return false;

	int i = 0;

	//searches for the item in the array
	while (items[i] != data)
	{
		i++;
	}

	for (int j = i; j < totalItems; j++)
	{
		//if the items in array are already empty, no need to shift items (return true)
		if (items[j + 1] == " ")
		{
			totalItems--;
			return true;
		}
		else
		{
			//otherwise if items in array are filled, shift items up a position in the array
			items[j] = (items[j + 1]);
		}
	}

	return false;
}

//prints list by running through a loop to output
//every item inserted in the array
void List::printList()
{
	for (int i = 0; i < totalItems; i++)
	{
		//prints in a list on a single line
		cout << "*" << items[i] << " ";
	}
	cout << endl;
}