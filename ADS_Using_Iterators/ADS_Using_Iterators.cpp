// ADS_Using_Iterators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ADS_Using_Iterators.h"
#include <list>
using namespace std;

void demoPrintUsingIterators();
void demoPrintFunctions();

void print(list<int> theList) {
	for (int x : theList)
		cout << x << endl;
}

void print(list<int>::iterator iter, list<int>::iterator end) {
	while (iter != end) {
		cout << *iter << endl;
		iter++;
	}
}

void print(list<int>::reverse_iterator iter, list<int>::reverse_iterator end) {
	while (iter != end) {
		cout << *iter << endl;
		iter++;
	}
}

int main()
{
	//demoPrintUsingIterators();
	demoPrintFunctions();
}

/// @brief Demos different methods of printing a list
void demoPrintUsingIterators()
{
	list<int> intList = { 1,2,3,4,5,6 };

	//loop and print
	for (int x : intList)
		cout << x << endl;

	cout << endl;

	//loop and print
	for (auto x : intList)
		cout << x << endl;

	cout << endl;

	//loop and print
	list<int>::iterator iter = intList.begin();
	while (iter != intList.end())
	{
		cout << *iter << endl;
		iter++;
	}

	cout << endl;

	//loop and print
	auto it = intList.end();
	while (it != intList.begin()) {
		it--;
		cout << *it << endl;
	}
}

/// @brief Demos how we can write many forms of a print function (i.e. using iterators, using templates)
void demoPrintFunctions()
{
	list<int> intList = { 1,2,3,4,5,6 };

	//non-generic print using list<int> parameter
	print(intList);

	cout << endl;

	//print all FORWARD with new iterator print
	auto start = intList.begin();
	auto end = intList.end();
	print(start, end);

	cout << endl;

	//print subset FORWARD with new iterator print
	start = intList.begin();
	end = intList.end();

	advance(start, 2);
	advance(end, -2);
	print(start, end);

	cout << endl;

	//print all in REVERSE with new reverse_iterator print
	auto rstart = intList.rbegin(); //ptr to end
	auto rend = intList.rend();		//ptr to begin
	print(rstart, rend);

	cout << endl;

	//print SUBSET in REVERSE with new reverse_iterator print
	rstart = intList.rbegin(); //ptr to end
	rend = intList.rend();		//ptr to begin
	advance(rstart, 2);
	advance(rend, -2);
	print(rstart, rend);
}