
/*************************************************************
Name: LinkedList.h
Code: Kira Corbett
Date: 5/20/2017
Desc: Class definitions of LinkedList
Includes Node Struct
*************************************************************/
#ifndef _LINKEDLIST_
#define _LINKEDLIST_

using namespace std;

const int MAX_NAMES = 10;

struct Node
{
	string data;
	Node* nextNode;
};

class LinkedList
{
public:
	LinkedList();
	/*===========================
	Desc: Default constructor
	Retn: True if successful
	Retn: False otherwise
	===========================*/
	
	~LinkedList();
	/*==================================
	Desc: Destructor; deletes every node
	Retn: True if successful
	Retn: False otherwise
	==================================*/

	bool insert(string data);
	/*==================================
	Desc: Inserts given string in list
	(in alphabetical order)
	Retn: True if successful
	Retn: False otherwise
	==================================*/

	bool remove(string data);
	/*====================================
	Desc: removes given string from list
	Retn: True if successful
	Retn: False otherwise
	====================================*/

	void print() const;
	/*====================================
	Desc: prints list in order
	Retn: void
	====================================*/

	int count() const;
	/* ==============================================
	Desc: returns a count of the number of
	strings in the list
	NOTE: Does NOT print the result of strings
	Retn: int
	============================================== */

	int find(string data) const;
	/* ==============================================
	Desc: finds item's place in list (e.g. 1 if first)
	Retn: Given string's position in list (1 if first)
	Retn: 0 if item not in the list
	============================================== */

	bool removeAll();
	/* ====================================
	Desc: removes all strings from the list
	Retn: True if the removeAll was successful
	Retn: False otherwise
	==================================== */

	LinkedList* duplicate();
	/* ====================================
	Desc: makes exact copy of the list
	Retn: return a pointer to the new list
	==================================== */

	void printReverse();
	/* ====================================
	Desc: prints the list in reverse order
	Retn: void
	==================================== */

private:
	Node * head;			//variable declaration for Node
};


//insert - inserts the given string in the list(in alphabetic order)
//if it’s not already there.Returns true if successful, false otherwise. No duplicates are allowed.

#endif