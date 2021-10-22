// ADS_Using_Iterators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ADS_Using_Iterators.h"
#include <list>
using namespace std;

void demoPrintUsingIterators();
void demoPrintFunctions();

//method declaration
template <typename Iter>
void print_temp(Iter iter, Iter end);

void print(list<int> theList) {
	for (int x : theList)
		cout << x << endl;
}

template <typename T>
void print(list<T> theList) {
	for (T x : theList)
		cout << x << endl;
}

template <typename T, typename E>
void print(T theList) {
	for (E x : theList)
		cout << x << endl;
}

template <typename Iter>
void print_temp(Iter iter, Iter end) {
	while (iter != end) {
		cout << *iter << endl;
		iter++;
	}
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

	//print subset REVERSE with new iterator print (4, 3)
	rstart = intList.rbegin(); //ptr to end
	rend = intList.rend();		//ptr to begin

	advance(rstart, 2); //move rstart iterator left 2
	advance(rend, -2);  //move rend iterator right 2

	print(rstart, rend);

	cout << "++++++++++++" << endl;

	//print all FORWARD with new template print
	start = intList.begin();
	end = intList.end();
	print_temp(start, end);

	//print using template function with doubles
	list<double> dblList = { 2.55, 5.7, 8.01, 9.99, 10.234 };
	print_temp(dblList.begin(), dblList.end());

	//reverse print using template function with chars
	list<char> charList = { 'a','e','i','o', 'u' };
	print_temp(charList.rbegin(), charList.rend());
}