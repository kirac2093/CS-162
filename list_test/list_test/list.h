/* ===============================================
Name: list.h
Code: Kira Corbett
Date: 4/20/2017
Desc: class header
=============================================== */

//preprocessor directives
#pragma once
#include <iostream>

using namespace std;

//declare constants
static const int MAX_ITEMS = 10;

class List
{
public:
	List();

	/* ===============================
	Return true if string inserted
	Return false if string not inserted
	================================ */
	bool insert(const string& data);

	/* ===============================
	Return true if empty
	Return false if otherwise
	================================ */
	bool empty() const;

	/* ===============================
	Return true if full
	Return false if otherwise
	================================ */
	bool full() const;

	/* ===============================
	Return true if item(s) in list
	Return false if otherwise
	================================ */
	bool List::inList(const string& theList) const;

	/* ===============================
	Return true if removal successful
	Return false if string not in list
	================================ */
	bool List::remove(const string& data);

	void printList();

private:
	string items[MAX_ITEMS];
	int totalItems;
};