#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

void rowDefin(char[][5], int&);
void columnDefin(char[][5], int&);
void crossDefin(char[][5], int&);
void gamestatus(char[][5]);
void computerdrop(char[][5]);
void gameDefin(char[][5], int&);
void computerFirst(char[][5], int&);
void userFirst(char[][5], int&);

int main()
{
	srand(time(0));
	char board[5][5] = {};
	int firstdrop;
	int gamesetter = 1;

	cout << "Welcome to the funny Omok game!\n\nThis is the game board.\n\n";
	cout << "    0   1   2   3   4\n" << "   -------------------\n";
	for (int i = 0; i < 5; ++i)
	{
		cout << i << " | ";
		for (int j = 0; j < 5; ++j)
		{
			board[i][j] = ' ';
			cout << board[i][j] << " | ";
		}
		cout << "\n   -------------------\n";
	}

	cout << "\nPlease select first drop.\n\nComputer = 1, User = 2\n\nWho? : ";
	cin >> firstdrop;
	while (firstdrop != 1 && firstdrop != 2)
	{
		cout << "\nOpen your eyes and select again.\n\n";
		cin >> firstdrop;
	}
	cout << "\nOK. If you want to exit, Please enter -1 -1 in your coordinate.\n";

	if (firstdrop == 1)
	{
		computerFirst(board, gamesetter);
	}

	else if (firstdrop == 2)
	{
		userFirst(board, gamesetter);
	}

	cout << "\n\nGame End.\n";
	return 0;
}

void rowDefin(char board[][5], int& gamesetter)
{
	for (int i = 0; i < 5; ++i)
	{
		int rowo = 0;
		int rowx = 0;

		for (int j = 0; j < 5; ++j)
		{
			if (board[i][j] == 'X')
			{
				++rowx;
			}
			else if (board[i][j] == 'O')
			{
				++rowo;
			}
		}
		if (rowx == 5 || rowo == 5)
		{
			if (board[i][4] == 'X')
				cout << "\nComputer Win!";
			else if (board[i][4] == 'O')
				cout << "\nUser Win!";
			gamesetter = 0;
		}
	}
}

void columnDefin(char board[][5], int& gamesetter)
{

	for (int i = 0; i < 5; ++i)
	{
		int columnx = 0;
		int columno = 0;

		for (int j = 0; j < 5; ++j)
		{
			if (board[j][i] == 'X')
				++columnx;
			else if (board[j][i] == 'O')
				++columno;
		}

		if (columnx == 5 || columno == 5)
		{
			if (board[4][i] == 'X')
				cout << "\nComputer Win!";
			else if (board[4][i] == 'O')
				cout << "\nUser Win!";
			gamesetter = 0;
		}
	}
}

void crossDefin(char board[][5], int& gamesetter)
{
	int cross1x = 0;
	int cross1o = 0;
	int cross2x = 0;
	int cross2o = 0;
	int i = 0;

	for (i = 0; i < 5; ++i)
	{
		if (board[i][i] == 'X')
			++cross1x;
		else if (board[i][i] == 'O')
			++cross1o;
	}

	if (cross1x == 5 || cross1o == 5)
	{
		if (board[4][4] == 'X')
			cout << "\nComputer Win!";
		else if (board[4][4] == 'O')
			cout << "\nUser Win!";
		gamesetter = 0;
	}

	int j = 4;

	for (int i = 0; i < 5; ++i) //(0,4) (1,3) (2,2) (3,1) (4,0)
	{
		if (board[i][j] == 'X')
		{
			++cross2x;
		}
		else if (board[i][j] == 'O')
		{
			++cross2o;
		}
		--j;
	}

	if (cross2x == 5 || cross2o == 5)
	{
		if (board[4][0] == 'X')
			cout << "\nComputer Win!";
		else if (board[4][0] == 'O')
			cout << "\nUser Win!";
		gamesetter = 0;
	}
}

void gamestatus(char board[][5])
{
	cout << "    0   1   2   3   4\n" << "   -------------------\n";
	for (int i = 0; i < 5; ++i)
	{
		cout << i << " | ";
		for (int j = 0; j < 5; ++j)
		{
			cout << board[i][j] << " | ";
		}
		cout << "\n   -------------------\n";
	}
}

void computerdrop(char board[][5])
{
	int x = rand() % 5;
	int y = rand() % 5;

	while (board[x][y] != ' ')
	{
		x = rand() % 5;
		y = rand() % 5;
	}

	board[x][y] = 'X';
}

void gameDefin(char board[][5], int& gamesetter)
{
	rowDefin(board, gamesetter);
	columnDefin(board, gamesetter);
	crossDefin(board, gamesetter);
}

void computerFirst(char board[][5], int& gamesetter)
{
	int x = 0;
	int y = 0;

	cout << "\nComputer first.\n";

	while (gamesetter == 1)
	{
		cout << "\nComputer drop\n\n";
		computerdrop(board);
		gamestatus(board);
		gameDefin(board, gamesetter);
		if (gamesetter == 0)
			break;
		cout << "\nYour turn. Please enter your coordinate : ";
		cin >> x >> y;
		if (x == -1 || y == -1)
			break;
		while (board[x][y] != ' ')
		{
			cout << "\nNot empty space. Please enter your coordinate again : ";
			cin >> x >> y;
		}
		cout << endl;
		board[x][y] = 'O';
		gamestatus(board);
		gameDefin(board, gamesetter);
	}
}

void userFirst(char board[][5], int& gamesetter)
{
	int x = 0;
	int y = 0;

	cout << "\nUser first.\n";

	while (gamesetter == 1)
	{
		cout << "\nYour turn. Please enter your coordinate : ";
		cin >> x >> y;
		if (x == -1 || y == -1)
			break;
		while (board[x][y] != ' ')
		{
			cout << "\nNot empty space. Please enter your coordinate again : ";
			cin >> x >> y;
		}
		cout << endl;
		board[x][y] = 'O';
		gamestatus(board);
		gameDefin(board, gamesetter);
		if (gamesetter == 0)
			break;
		cout << "\nComputer drop.\n\n";
		computerdrop(board);
		gamestatus(board);
		gameDefin(board, gamesetter);
	}
}