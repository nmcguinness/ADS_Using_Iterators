#include <iostream>
#include <list>
#include "ADS_Using_Iterators.h"
#include "Utilities.h"

using namespace std;

void demoPrintUsingFor();
void demoPrintUsingIterators();
void demoPrintFunctions();
void demoConstIterators();

int main()
{
	cout << "demoPrintUsingFor............." << endl;
	demoPrintUsingFor();

	cout << "demoPrintUsingIterators......." << endl;
	demoPrintUsingIterators();

	cout << "demoPrintFunctions............" << endl;
	demoPrintFunctions();

	cout << "demoConstIterators............" << endl;
	demoConstIterators();
}

/// @brief Demos different methods of printing a list
void demoPrintUsingFor()
{
	list<int> intList = { 1,2,3,4,5,6 };

	////traditional for(int) loop
	//int length = intList.size();
	//for (int i = 0; i < length; i++)
	//{
	//	cout << intList[i] << endl; //list doesn't have a [] or get() or at[] - we must use an iterator
	//}

	//loop and print
	for (int x : intList)  //foreach(int x in intList)
		cout << x << endl;

	cout << endl;

	//loop and print
	for (auto x : intList)
		cout << x << endl;

	cout << endl;
}

void demoPrintUsingIterators()
{
	list<int> intList = { 1,2,3,4,5,6 };

	//loop and print FORWARDS using iterator
	list<int>::iterator iter = intList.begin();
	while (iter != intList.end())
	{
		cout << *iter << endl;
		iter++;
	}

	cout << endl;

	//loop and print BACKWARDS using iterators
	auto it = intList.end();
	while (it != intList.begin()) {
		it--;
		cout << *it << endl;
	}
}

//constant iterator - cbegin, cend
void demoConstIterators()
{
	list<int> intList1 = { 1,2,3,4,5,6 };
	list<int>::iterator constIt1 = intList1.begin();

	// display vector elements using const_iterator
	while (constIt1 != intList1.end()) {
		cout << *constIt1 << endl;
		*constIt1 += 10;
		constIt1++;
	}

	list<int> intList2 = { 1,2,3,4,5,6 };
	list<int>::const_iterator constIt2 = intList2.cbegin();

	// display vector elements using const_iterator
	while (constIt2 != intList2.end()) {
		cout << *constIt2 << endl;

		//line below will not compile
		//*constIt2 += 10;
		constIt2++;
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