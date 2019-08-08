/*
 * Deque.h
 *
 *  Created on: Jul 10, 2019
 *      Author: alex
 */

#ifndef DEQUE_H_
#define DEQUE_H_

template <typename E>
class Deque {
private:
	int maxSize;
	int front;
	int rear;
	E *array;

public:
	// Constructor. Note that array requires one more space than the actual max size of deque so that we can check for wrap-around
	Deque(int size = 100) {
		maxSize = size + 1;
		rear = 0; front = 1;
		array = new E[maxSize];
	}

	// Destructor
	virtual ~Deque() {
		delete [] array;
	}

	// "Remove" all elements
	void clear() {
		rear = 0; front = 1;
	}

	// Place element at rear
	void push_rear(const E& element) {
		// Check if deque is full
		if ((rear + 2) % maxSize == front) throw "Deque is full.";
		// Circular increment rear
		rear = (rear + 1) % maxSize;
		array[rear] = element;
	}

	// Place element at front
	void push_front(const E& element) {
		// Check if deque is full
		if ((rear + 2) % maxSize == front) throw "Deque is full.";
		// Circular decrement front
		front = (front + maxSize - 1) % maxSize;
		array[front] = element;
	}

	// Pop from front
	E pop_front() {
		if (length() == 0) throw "Deque is empty.";
		// Get element
		E element = array[front];
		// Circular increment front
		front = (front + 1) % maxSize;
		return element;
	}

	// Pop from rear
	E pop_rear() {
		if (length() == 0) throw "Deque is empty.";
		// Get element
		E element = array[rear];
		// Circular decrement rear
		rear = (rear + maxSize - 1) % maxSize;
		return element;
	}

	// Peek at front
	const E& peek_front() {
		if (length() == 0) throw "Deque is empty.";
		return array[front];
	}

	// Peek at rear
	const E& peek_rear() {
		if (length() == 0) throw "Deque is empty.";
		return array[rear];
	}

	// Size of deque
	int length() {
		// Count inclusively; additional maxSize ensures length will never return negative value
		return (rear + maxSize - front + 1) % maxSize;
	}
};

#endif /* DEQUE_H_ */
