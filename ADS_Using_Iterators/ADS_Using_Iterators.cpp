// ADS_Using_Iterators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ADS_Using_Iterators.h"
#include <list>
using namespace std;

void demoUsingListIterators();

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

int main()
{
	demoUsingListIterators();
}

void demoUsingListIterators()
{
	list<int> intList = { 1,2,3,4,5,6 };
	//print(intList);

	//print all with new iter print
	auto start = intList.begin();
	auto end = intList.end();
	print(start, end);

	//advance and print a subset
	advance(start, 2);
	print(start, end);

#pragma region Loop demos

	////loop and print
	//for (int x : intList)
	//	cout << x << endl;

	////loop and print
	//for (auto x : intList)
	//	cout << x << endl;

	////loop and print
	//list<int>::iterator iter = intList.begin();
	//while (iter != intList.end())
	//{
	//	cout << *iter << endl;
	//	iter++;
	//}

	////loop and print
	//auto it = intList.end();
	//while (it != intList.begin()) {
	//	it--;
	//	cout << *it << endl;
	//}
#pragma endregion
}