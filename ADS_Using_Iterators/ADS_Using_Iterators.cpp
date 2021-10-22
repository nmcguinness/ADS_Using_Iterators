// ADS_Using_Iterators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ADS_Using_Iterators.h"
#include <list>
using namespace std;

void demoUsingListIterators();

int main()
{
	demoUsingListIterators();
}

void demoUsingListIterators()
{
	list<int> intList = { 7,8,9,10 };

#pragma region Loop demos

	//loop and print
	for (int x : intList)
		cout << x << endl;

	//loop and print
	for (auto x : intList)
		cout << x << endl;

	//loop and print
	list<int>::iterator iter = intList.begin();
	while (iter != intList.end())
	{
		cout << *iter << endl;
		iter++;
	}

	//loop and print
	auto it = intList.end();
	while (it != intList.begin()) {
		it--;
		cout << *it << endl;
	}
#pragma endregion
}