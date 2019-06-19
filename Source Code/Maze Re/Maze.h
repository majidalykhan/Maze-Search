#include <iostream>
#include <Windows.h>
#include "Stack.h"
#include "Position.h"

#ifndef MAZE_H // Include guards
#define MAZE_H

const int ROW = 20;
const int COL = 20;
const char Wall = '|';
const char Ground = '-';
const char Path = ' ';
const char Start = 'S';
const char Goal = 'G';
const char Player = '*';
const char Visited = '.';

class Maze
{
private:

public:

	Position position; // Current Position
	Position starting_position; // Starting position in maze or S
	Position goal_position; // Goal position in maze or G
	Stack stack;

	Maze();
	static char maze[][20];
	void Display_Maze();
	void Move_Up();
	void Move_Down();
	void Move_Left();
	void Move_Right();
	void DepthFirstSearch(Position position);
	void BackTrack(Position position);
	void ClearScreen();
};

#endif