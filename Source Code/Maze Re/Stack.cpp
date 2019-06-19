#include "Stack.h"

Stack::Stack()
{
	mytop = -1;
}

bool Stack::empty()
{
	if (mytop == -1)
		return true;
	else
		return false;
}

bool Stack::full()
{
	if (mytop >= max_size)
		return true;
	else
		return false;
}

Position Stack::top()
{
	if (mytop >= 0)
		return myarray[mytop];
	else
		cout << "Stack is Empty ! " << endl;
}

void Stack::push(Position position)
{
	if (mytop < max_size)
	{
		mytop = mytop + 1;
		myarray[mytop] = position;
	}
	else
		cout << "Stack Already Full, Cant Push" << endl;
}

Position Stack::pop()
{
	if (mytop >= 0)
		return myarray[mytop--];
	else
		cout << "Stack is empty ! " << endl;
	//return;
}

void Stack::display()
{
	top();
}


