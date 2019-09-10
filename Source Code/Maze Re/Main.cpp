#include <iostream>
#include <Windows.h>
#include "Maze.h"
#include "Stack.h"
using namespace std;

int main()
{
	Maze maze;
    //Checking for git
	maze.starting_position.i = 1;
	maze.starting_position.j = 1;

	maze.position = maze.starting_position; //Set Position of Player to Starting Position
	
	maze.goal_position.i = 6;
	maze.goal_position.j = 1;

	maze.DepthFirstSearch(maze.position);

	
	system("pause");
	return 0;
}

