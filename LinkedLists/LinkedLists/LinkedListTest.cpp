/*************************************************************
Name: LinkedListTest
Code: Kira Corbett
Date: 5/20/2017
Desc: Practice implementing and using an ordered linked list.
Stores a unique list of string in alphabetical order
(managed by a linked list class.)
************************************************************/

#include <iostream>
#include <cstring>
#include "LinkedList.h"

using namespace std;

int main()
{
	//declares a LinkedList pointer and dynamically allocates a LinkedList object
	LinkedList* list1 = new LinkedList;
	LinkedList* list2;

	//inserts the following strings (and prints after each insertion)
	cout << "====================INSERT, PRINT, & COUNT LIST 1==============" << endl;
	list1->insert("Bill");
	list1->print();
	list1->insert("Adam");
	list1->print();
	list1->insert("Zorro");
	list1->print();
	list1->insert("Kelly");
	list1->print();
	list1->insert("Chris");
	list1->print();
	list1->insert("Kelly");
	list1->print();

	//print out the total number of items in the list1
	cout << "Total Items in List 1: " << list1->count() << endl;

	//make a copy of the list
	list2 = list1->duplicate();

	//remove from the original list
	cout << "=========================REMOVE FROM LIST 1====================" << endl;
	list1->remove("Zorro");
	list1->print();
	list1->remove("Charlie");
	list1->print();
	list1->remove("Becky");
	list1->print();
	list1->remove("Adam");
	list1->print();
	list1->remove("Kelly");
	list1->print();

	//insert to new list
	cout << "====================INSERT, COUNT, & PRINT LIST 2=============" << endl;
	list2->insert("Sam");
	list2->print();
	cout << "Total Items in List 2: " << list2->count() << endl;

	//print out the position of the following
	cout << "============================FIND LIST 1========================" << endl;
	cout << "[0] = DOES NOT EXIST  OR [1+] = POSITION IN LIST" << endl;
	cout << "George is position " << list1->find("George") << endl;
	cout << "Adam is position " << list1->find("Adam") << endl;
	cout << "Kelly is position " << list1->find("Kelly") << endl;

	list1->removeAll();
	delete list1;
	delete list2;

	cout << endl;

	cout << "Done" << endl;

	return 0;
}