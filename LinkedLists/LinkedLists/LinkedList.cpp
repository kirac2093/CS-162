/*************************************************************
Name: LinkedList.cpp
Code: Kira Corbett
Date: 5/20/2017
Desc: Class implementation of LinkedList;
class functions perform various operations with strings:
INSERT, REMOVE, PRINT, COUNT, FIND, REMOVE+ALL, DUPLICATE,
PRINT_REVERSE
************************************************************/
#include <iostream>
#include <string>
#include <cstring>
#include "LinkedList.h"

using namespace std;

//default constructor
LinkedList::LinkedList()
{
	//sets head to NULL
	head = NULL;
}

//destructor
LinkedList::~LinkedList()
{
	//if space was allocated, destructor deletes nodes
	if (head != NULL)
	{
		delete head;
		head = NULL;
	}
	delete head;
	head = NULL;
}

/*=============================================================
Desc: Inserts given string in list (in alphabetical order)
Retn: True if successful
Retn: False otherwise
==============================================================*/
//==========================================================MAKE SURE DUPLICATES DON'T PASS
bool LinkedList::insert(string data)
{
	//dynamically allocate memory for newNode
	Node* newNode = new Node;
	newNode->data = data;		//stores data (from main) in the new node
	newNode->nextNode = NULL;

	//=================CASE 1==================
	//checks if list is empty
	//Note: The node containing the new item
	//	    is the only and first node of list
	//========================================
	if (head == NULL)
	{
		head = newNode;
		return true;
	}

	//============================CASE 2====================================
	//checks if the item is less than the first item (smallest item of list)
	//If it is the smallest item , the new item goes at the beginning of the list.
	//Therefore, we need to adjust the list's head pointer (head).
	//======================================================================
	if (newNode->data.compare(head->data) < 0)
	{
		newNode->nextNode = head;
		head = newNode;
		return true;
	}

	//============================CASE 3======================
	//checks if there is already an existing item in the list
	//========================================================
	Node* trail = head;

	while (trail != NULL)
	{
		if (newNode->data.compare(trail->data) == 0)
		{
			return false;
		}
		trail = trail->nextNode;
	}

	//============================CASE 3==========================
	//if the item is not less than the first item
	//the new item is placed somewhere after the first item
	//============================================================
	Node* current = head->nextNode;
	//trail node initialized above ^ ^ ^ in case 3

	//checks if the current address is not NULL 
	//AND that the newNode data entry is greater than the current node data entry
	while (current != NULL && newNode->data.compare(current->data) > 0)
	{
		newNode->data > current->data;
		trail = current;
		current = current->nextNode;
	}
	newNode->nextNode = trail->nextNode;
	trail->nextNode = newNode;
	return true;
}

/*====================================
Desc: removes given string from list
Retn: True if successful
Retn: False otherwise
====================================*/
bool LinkedList::remove(string data)
{
	//============ CASE 1 ===========
	//if there is an empty list
	//===============================
	if (head == NULL)
	{
		return false;
	}

	//======================= CASE 2 =========================
	//deleting the first item of the list
	//Note: Deleting the first item of the list is a special 
	//		case because it requires modification of the head
	//========================================================
	if (head->data == data)
	{
		//create a new pointer as a temporary place for the head to point to
		//(removes node from list)
		Node* temp = head;
		head = head->nextNode;		//point to second node (removes head from pointing to first node)

									//delete temporary pointer
									//(memory is still occupied by node and this memory is inaccessible so we deallocate the memory)
		delete temp;
		return true;
	}
	//==================== CASE 3 =================
	//deleting an item somewhere after the 1st item
	//=============================================
	Node* trail = head;					//set trail to head since there is nothing before first node
	Node* nodeToDelete = head->nextNode;	//stores data in nextNode address

											//compare current data with nextNode data
	while (nodeToDelete != NULL && nodeToDelete->data.compare(data) < 0)
		//comparing ints remove the compare function: nodeToDelete->data < data
	{
		trail = nodeToDelete;
		nodeToDelete = nodeToDelete->nextNode;
	}

	if (nodeToDelete != NULL && nodeToDelete->data == data)
	{
		//set the nextNode trail data address to the nodeToDelete address
		//then deallocate memory
		trail->nextNode = nodeToDelete->nextNode;
		delete nodeToDelete;
		return true;
	}
	return false;
}

/*====================================
Desc: prints list in order
Retn: void
====================================*/
void LinkedList::print() const
{
	Node* current = head;

	while (current != NULL)
	{
		cout << current->data;
		if (current->nextNode != NULL)				//as long as the nextNode field is not NULL
		{
			cout << ", ";						//it prints a comma after the data
		}
		current = current->nextNode;
	}
	cout << endl;
}

/* ==============================================
Desc: returns a count of the number of
strings in the list
NOTE: Does NOT print the result of strings
Retn: int
============================================== */
int LinkedList::count() const
{
	Node* current = head;
	int count = 0;

	//circulates through list to count each item by 1
	while (current != NULL)
	{
		current = current->nextNode;
		count++;
	}
	return count;
}

/* ==============================================
Desc: finds item's place in list (e.g. 1 if first)
Retn: Given string's position in list (1 if first)
Retn: 0 if item not in the list
============================================== */
int LinkedList::find(string data) const
{
	Node* current = head;
	int stringPosition = 1;

	//============ CASE 1 ===========
	//return 0 if the list is empty	 
	//==============================
	if (head == NULL)
	{
		return 0;
	}

	//==================== CASE 2 ========================
	//		circulate through items in the list to
	//		check each item in the list. If the item
	//		in the list is not equal to the given string
	//		return 0 otherwise return its position
	//====================================================
	while (current->nextNode != NULL && current->data != data)
	{
		current = current->nextNode;
		stringPosition++;
	}

	if (current->nextNode == NULL && current->data != data)
	{
		return 0;
	}
	else
	{
		return stringPosition;
	}
}

/* ====================================
Desc: removes all strings from the list
Retn: True if the removeAll was successful
Retn: False otherwise
==================================== */
bool LinkedList::removeAll()
{
	Node* current = NULL;
	Node* trail = NULL;
	int count = 0;

	//CASE 1: empty list
	if (head == NULL)
	{
		return false;
	}

	current = head;
	head = NULL;

	//if current->nextNode has data
	//set the previous (trail) data to the current
	//and the current to the following data 
	//then delete the previous
	while (current->nextNode != NULL)
	{
		trail = current;
		current = current->nextNode;
		delete trail;
	}

	//delete current (to finish removing all nodes)
	delete current;
	count = 0;
	return true;
}

/* ====================================
Desc: makes exact copy of the list
Retn: return a pointer to the new list
==================================== */
LinkedList* LinkedList::duplicate()
{


	LinkedList* newList = new LinkedList;	//create new pointer list
	Node* current = head;					//set current to point to head of list

											//copy the first node
	Node* newNode = new Node;				//create a new node pointer

	newList->head = newNode;				//newList head is set to the newNode
	newList->head->data = current->data;	//copy the data
	newList->head->nextNode = NULL;			//set the nextNode field of the node to NULL

											//copy the remaining list	
	current = head->nextNode;
	Node* trail = newList->head;			//make the trail (previous) point to first node of newList

	while (current != NULL)
	{
		Node* newNode = new Node;			//create a node
		newNode->data = current->data;		//copy the data
		newNode->nextNode = NULL;			//set the nextNode field of newNode to NULL
		trail->nextNode = newNode;			//attach newNode after trail
		trail = newNode;					//trail points to the actual last node
		current = current->nextNode;		//current points to the nextNode node
	}

	return newList;

}

/* ====================================
Desc: prints the list in reverse order
Retn: void
==================================== */
void LinkedList::printReverse()
{
	Node* newHead = NULL;
	Node* current = NULL;					//pointer to traverse through list
	Node* temp;

	current = head;

	while (current != NULL)
	{
		temp = current;						//stabalize temp pointer to point one step behind
		current = current->nextNode;			//current points to the following field
		temp->nextNode = newHead;				//circulates backwards from newHead
		newHead = temp;
	}
	head = newHead;
}


//for loop suggestion
//for (current = head; current;)		//go through list from head 