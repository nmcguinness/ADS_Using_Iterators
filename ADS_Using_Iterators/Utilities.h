#pragma once
#include <iostream>
#include <list>
using namespace std;

//method declaration here just to remind you what a templated declaration looks like
//template <typename Iter>
//void print_temp(Iter iter, Iter end);

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
