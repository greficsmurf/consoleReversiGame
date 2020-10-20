// Reversi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Board.h"
#include "ReversiConsoleView.h"
#include <time.h>

using namespace std;

int main()
{
	string x, y;
	char stone;
	Board* board;
	srand(time(NULL));
	int coin = rand() % 2;
	if (coin == 0)
		stone = 'x';
	else
		stone = 'o';

	cout << "The starting point of a board game\n"
		<< "Please enter the size(x, y)(default: 8 8) of the game, for better expirience set it to 8 8, \nx = ";
	cin >> x;
	cout << "\ny = ";
	cin >> y;
	cout << "Board is created, to clear the board set x to < clr >, to exit set x to < exit > \n";
	cout << "You can place your coin on * places\n";

	/*
		try catch block is used to prevent wrong input like string instead of number
	*/

	try {
		board = new Board(stoi(x), stoi(y));
	}
	catch (exception e) {
		cout << "Wrong size initializing default table \n";
		board = new Board(8, 8);		// if input is wrong, default table is initialized
	}
	
	ReversiConsoleView* view = new ReversiConsoleView(*board);	//creating new instance of object and passing 
																// another object which contains table properties
	//board->findLegalMoves(stone);

	//view->print();

	while (x != "exit") {
		board->findLegalMoves(stone);
		view->print();
		cout << "\n\n<-------------------- TURN OF < " << stone << " > ------------>" << "\n\n";
		cout << "Please enter a position (x,y) < exit > instead of x to exit, \nx = ";
		cin >> x;

		if (x == "exit") break;
		if (x == "clr") { 
			board->clearBoard(); 
			continue;
		}
		cout << "\ny = ";
		cin >> y;


		/*
			try catch block is used for the same reason as before
		*/

		try {
			if (!board->setPosition(stoi(x), stoi(y), stone)) continue;
		}
		catch (exception e) {
			cout << "Wrong position\n";
			continue;
		}

		if (stone == 'x')
			stone = 'o';
		else
			stone = 'x';
	}
}


