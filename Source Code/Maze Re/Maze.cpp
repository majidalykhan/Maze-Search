#include "Maze.h"
using namespace std;

Maze::Maze(){}

char Maze::maze[][20] =
//   0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
{ { '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' }// 0
, { '|', 'S', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' }// 1
, { '|', ' ', '|', ' ', '|', ' ', '|', '-', '-', '-', '-', '-', '-', ' ', '-', '-', '-', '-', '-', '|' }// 2
, { '|', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|' }// 3
, { '|', ' ', '|', ' ', '|', '-', '-', ' ', '|', '-', '|', ' ', '|', '-', '-', '-', '-', '-', ' ', '|' }// 4
, { '|', '-', '-', '-', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|' }// 5
, { '|', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', '|', ' ', '|', ' ', '-', '-', '-', '-', '-', '|' }// 6
, { '|', ' ', '|', ' ', '|', ' ', '|', '-', ' ', '|', '-', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', '|' }// 7
, { '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', '-', '-', ' ', '|' }// 8
, { '|', ' ', '|', ' ', '|', ' ', '|', ' ', '-', '|', ' ', ' ', '|', '-', '-', '-', '|', '|', ' ', '|' }// 9
, { '|', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', '|' }// 10
, { '|', ' ', '|', ' ', '|', '-', '-', '-', ' ', '|', ' ', '|', ' ', '|', ' ', '-', '-', '|', ' ', '|' }// 11
, { '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', '|' }// 12
, { '|', ' ', '-', '-', '|', ' ', '|', '-', ' ', '|', ' ', '|', ' ', '|', ' ', '-', '-', ' ', '-', '|' }// 13
, { '|', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' }// 14
, { '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', '-', '-', '-', ' ', '|' }// 15
, { '|', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' }// 16
, { '|', ' ', '|', ' ', '|', '-', '-', '-', '-', '-', ' ', '|', ' ', '|', '-', '-', '-', '-', ' ', '|' }// 17
, { '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' }// 18
, { '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' }// 19
};


void Maze::Display_Maze()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
			cout << maze[i][j];
		cout << endl;
	}
	cout << endl;
	cout << "* = Player" << endl;
	cout << "S = Starting Position" << endl;
	cout << "G = Goal Position" << endl;
}

void Maze::DepthFirstSearch(Position position)
{
	ClearScreen();
	maze[position.i][position.j] = Player; // Current position = Player (*)
	maze[starting_position.i][starting_position.j] = Start; // Player will Start from S
	maze[goal_position.i][goal_position.j] = Goal; // Player will reach to G
	Display_Maze(); // Display maze after setting of positions
	stack.push(position); // Push Current position into stack
	
	Sleep(100);

	cout << endl;

	if (maze[position.i][position.j] == maze[goal_position.i][goal_position.j]) // Base Case, If current position
		                                                                        // equals to Goal position
	{
		cout << " ---------------------- Player has reached to Goal ----------------------" << endl << endl;

		// show path
		Position path;
		cout << " ---------------------- Visited Paths in Maze are ----------------------- " << endl << endl;
		while (!stack.empty())
		{
			path = stack.pop(); // Store all Positions into path untill Stack is Empty
			cout << path.i <<","<< path.j << " | ";   // Display Position from maze
		}
		cout << endl << endl;
		cout << "           <------------------------------------------------------------>" << endl << endl;
		system("pause");
		exit(0); // When reached to Goal, Exit program.
		
	}

	if (maze[position.i][position.j + 1] != Wall && maze[position.i][position.j + 1] != Ground &&
		maze[position.i][position.j + 1] != Visited) // If in Same row & Right Coloum there is no Wall, Ground or Dead End
	{
		maze[position.i][position.j] = Visited; // Set Current Position to Visited(.)
		Position moved_position(position.i, position.j + 1); // Decide to Move Right and Store Next position in moved_position
		DepthFirstSearch(moved_position); // Recall function with (new) moved_position
	}

	if (maze[position.i + 1][position.j] != Wall && maze[position.i + 1][position.j] != Ground &&
		maze[position.i + 1][position.j] != Visited) // If in Down row & Same Coloum there is no Wall, Ground or Dead End
	{
		maze[position.i][position.j] = Visited; // Set Current Position to Visited(.)
		Position moved_position(position.i + 1, position.j); // Decide to Move Down and Store Next position in moved_position
		DepthFirstSearch(moved_position); // Recall function with (new) moved_position
	}

	if (maze[position.i][position.j - 1] != Wall && maze[position.i][position.j - 1] != Ground &&
		maze[position.i][position.j - 1] != Visited) // If in Same row & Left Coloum there is no Wall, Ground or Dead End
	{
		maze[position.i][position.j] = Visited; // Set Current Position to Visited(.)
		Position moved_position(position.i, position.j - 1); // Decide to Move Left and Store Next position in moved_position
		DepthFirstSearch(moved_position); // Recall function with (new) moved_position
	}

	if (maze[position.i - 1][position.j] != Wall && maze[position.i - 1][position.j] != Ground  &&
		maze[position.i - 1][position.j] != Visited) // If in Up row & Same Coloum there is no Wall, Ground or Dead End
	{
		maze[position.i][position.j] = Visited; // Set Current Position to Visited(.)
		Position moved_position(position.i - 1, position.j); // Decide to Move Up and Store Next position in moved_position
		DepthFirstSearch(moved_position); // Recall function with (new) moved_position
	}

	BackTrack(position); //Check Dead-End
	
}

void Maze::BackTrack(Position position)
{
	if (!stack.empty())
	{
		maze[position.i][position.j] = Visited; // Set Current Position to Visited (.)
		stack.pop(); // Pop Current Position 
		Position moved_position = stack.pop(); // Pop Previous Position also to avoid Infinte loop
		DepthFirstSearch(moved_position); // Recall function with new Calculated position (Previous position)

	}
}

void Maze :: ClearScreen()
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}