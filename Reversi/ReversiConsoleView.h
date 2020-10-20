#pragma once
#include "Board.h"
#include <string>
#include <iostream>
using namespace std;
class ReversiConsoleView
{
public:
	Board _board;
	ReversiConsoleView(Board& board) {
		_board = board;
	}


	void print() {
		int x = _board.getX();
		int y = _board.getY();
		char** table = _board.getTable();
		for (int i = 0; i < x+1; i++) {
			for (int j = 0; j < y+1; j++) {
				cout << table[i][j] << " ";
			}
			cout << "\n";
		}
	}


};

