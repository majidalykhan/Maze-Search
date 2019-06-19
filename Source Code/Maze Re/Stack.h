#include <iostream>
#include "Position.h"
using namespace std;

#ifndef STACK_H
#define STACK_H

const int max_size = 1000;

class Stack
{
private:
	Position myarray[max_size];
	int mytop;

public:

	Stack();
	bool empty();
	bool full();
	Position top();
	void push(Position);
	Position pop();
	void display();
};


#endif