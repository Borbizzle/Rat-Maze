//============================================================================
// Name       : Chance Borba
// Class      :  CS 2500
// Due Date   : 10 - 24 -18
// Assignment : Rat Mazes
// Description : This program reads in a maze of # and . that trapped a mouse. In this program
// we lead the rat out of the maze and display it.
//============================================================================


#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 5;
typedef char Mazes[SIZE][SIZE];

class Rats
{
public:
	void readIn();
	void printMaze(Mazes maze);
	bool solve(Mazes startingMaze, int x, int y);

private:
	ifstream fin;
	bool outBounds(int x, int y);

};
int main()
{
	Rats rat;
	Mazes startingMaze = {'.', '#', '.', '#', '#',
			  	  	  	  '.', '#', '.', '.', '.',
						  '.', '.', '.', '#', '.',
						  '.', '#', '.', '#', '.',
						  '#', '.', '.', '#', 'X'};

	rat.readIn();
	rat.printMaze(startingMaze);

	if(rat.solve(startingMaze, 0, 0))
		cout << "The rat found the cheese";
	else
		cout << "No path found";

	return 0;
}


void Rats::readIn()
{
	fin.open("ratmaze.txt");

}
void Rats::printMaze(Mazes maze)
{
	for (int x = 0; x < SIZE; x++) {
		for (int y = 0; y < SIZE; y++) {
			cout << maze[x][y] << " ";
		}
		cout << endl;
	}
}
bool Rats::outBounds(int x, int y){

return ( x < 0 || y < 0 || x >= SIZE|| y >= SIZE);
}

bool Rats::solve(Mazes startingMaze, int x, int y){
	if(outBounds(x, y)){// out of the maze
		return false;
	}else if (startingMaze[x][y] == 'X'){
		cout << endl << "Solution: \n";
		printMaze(startingMaze);
		return true;
	}else if (startingMaze[x][y] != '.'){// hit a wall
		return false;

	}else{
	// we are on a n empty square, but not home yet.
		startingMaze[x][y] = '@';
		return (solve(startingMaze, x + 1,y) ||
				solve(startingMaze, x - 1,y) ||
				solve(startingMaze, x,y - 1) ||
				solve(startingMaze, x,y + 1));
	}
}
