//Simple Battleship Game
//Put in coordinates guess to try and hit a battleship, get all 10 and you win!
//Author: Liam O'Neill
//Finished on 12/5/2019

#include <iostream>
#include <ctime>

using namespace std;

const int rows = 10;
const int elements = 10;

int shipmax = 10;

int matrix[rows][elements];

void Clear()
{
	for(int i=0; i < rows; i++)
	{
		for(int j=0; j < elements; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void Show()
{
	for(int i=0; i < rows; i++)
	{
		for(int j=0; j < elements; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int ShipNumber()
{
	int c = 0;

	for(int i=0; i < rows; i++)
	{
		for(int j=0; j < elements; j++)
		{
			if(matrix[i][j] == 1)
				c++;
		}
	}

	return c;
}

void SetShips()
{
	int s = 0;
	while(s < shipmax)
	{
		int x = rand() % rows;
		int y = rand() % elements;
		if (matrix[x][y] != 1)
		{
			s++;
			matrix[x][y] = 1;
		}
	}
}

bool Attack(int x, int y)
{
	if(matrix[x][y] == 1)
	{
		matrix[x][y] = 2;
		return true;
	}
	return false;
}

int main()
{
	srand(time(NULL));
	Clear();
	SetShips();
	int coord1,coord2;
	char cue;
	while(1)
	{
		cout << "Set location for possible target: "; cin >> coord1 >> coord2;
		if(Attack(coord1,coord2))
			cout << "You hit!" << endl;
		else
			cout << "Sorry, not a hit" << endl;
		cout << "Number of ships left: " << ShipNumber() << endl;
		cout << "Would you like to surrender? [y/n]"; cin >> cue;
		if(cue == 'y')
				break;
	}
	cout << "Game Over!" << endl;
	Show();
	system("pause");
	return 0;
}