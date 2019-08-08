/*
 * DequeTest.cpp
 *
 * Driver to test the deque implementation.
 *
 *  Created on: Aug 8, 2019
 *      Author: alex
 */

#include "Deque.h"
#include <iostream>
using std::cout;

int main() {
	Deque<int> deque;

	// Test error
	try {
		deque.pop_front();
	} catch (char const* e) {
		cout << "An exception occurred: " << e << "\n";
	}

	// Test push
	for (int i = 0; i < 10; ++i) {
		deque.push_front(i);
		deque.push_rear(i);
	}

	// Test peek and pop front
	int cur_length = deque.length();
	cout << "Deque is of length " << cur_length << ": \n";
	for (int i = 0; i < cur_length; ++i) {
		cout << deque.peek_front() << "\n";
		cout << deque.pop_front() << "\n";
	}
	cout << "\n";

	cout << "Deque should be empty: " << deque.length() << "\n";

	// Rebuild
	for (int i = 0; i < 10; ++i) {
		deque.push_front(i);
		deque.push_rear(i);
	}

	// Test peek and pop rear
	cur_length = deque.length();
	cout << "Reverse deque is of length " << cur_length << ": \n";
	for (int i = 0; i < cur_length; ++i) {
		cout << deque.peek_rear() << "\n";
		cout << deque.pop_rear() << "\n";
	}
	cout << "\n";

	cout << "Deque should be empty: " << deque.length() << "\n";

	// Rebuild
	for (int i = 0; i < 10; ++i) {
		deque.push_front(i);
		deque.push_rear(i);
	}

	// Test clear
	cout << "Deque has length: " << deque.length() << "\n";
	deque.clear();
	cout << "Deque should be empty: " << deque.length();

}


