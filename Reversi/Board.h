#pragma once
#include<iostream>;
#include<string>;
using namespace std;
class Board
{
public: 
	Board() {}
	Board(int x, int y) {
		this->x = x;
		this->y = y;
		initTable();
	}

	bool setPosition(int x, int y, char stone) {
		char opponentStone = 'x';
		if (stone == 'x')
			opponentStone = 'o';
		if (x >= this->x || y >= this->y) {
			return false;
		}
		if (table[x][y] != '*') {
			cout << "Position is not allowed, only < * > is appropriate\n";
			return false;
		}
		table[x][y] = stone;
		reverse(x,y,stone, opponentStone);
		return true;
		
	}
	void clearBoard() {
		initTable();
	}
	void clearLegalMoves() {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (table[i][j] == '*') {
					table[i][j] = '.';
				}
			}
		}
	}
	void reverse(int posY, int posX, char stone, char opponentStone) {
		bool isSet = false;
		bool isNotFirst = false;
		char possibleReverseChar = '-';
		int tempX;
		int tempY;
		// X
		for (int i = posX; i < x; i++) {
		
			if (table[posY][i] == opponentStone) {

				table[posY][i] = possibleReverseChar;
				isSet = true;
				continue;
			}

			if (isNotFirst && isSet && table[posY][i] == stone) {
				replaceReverse(stone);
				isSet = false;
				break;
			}
			if (!isNotFirst) isNotFirst = true;

			if (table[posY][i] == '.') {

				replaceReverse(opponentStone);
				break;
			}
			
		}
		isSet = false;
		for (int i = posX; i >= 0; i--) {
			
			if (table[posY][i] == opponentStone) {

				table[posY][i] = possibleReverseChar;
				isSet = true;
				continue;
			}

			if (isNotFirst && isSet && table[posY][i] == stone) {
				replaceReverse(stone);
				isSet = false;
				break;
			}
			if (!isNotFirst) isNotFirst = true;

			if (table[posY][i] == '.') {

				replaceReverse(opponentStone);
				break;
			}

		}
		isSet = false;
		// Y
		for (int i = posY; i < y; i++) {
			if (table[i][posX] == opponentStone) {

				table[i][posX] = possibleReverseChar;
				isSet = true;
				continue;
			}

			if (isNotFirst && isSet && table[i][posX] == stone) {
				replaceReverse(stone);
				isSet = false;
				break;
			}
			if (!isNotFirst) isNotFirst = true;

			if (table[i][posX] == '.') {

				replaceReverse(opponentStone);
				break;
			}
		}
		isSet = false;
		for (int i = posY; i >= 0; i--) {

			if (table[i][posX] == opponentStone) {

				table[i][posX] = possibleReverseChar;
				isSet = true;
				continue;
			}

			if (isNotFirst && isSet && table[i][posX] == stone) {
				replaceReverse(stone);
				isSet = false;
				break;
			}
			if (!isNotFirst) isNotFirst = true;

			if (table[i][posX] == '.') {

				replaceReverse(opponentStone);
				break;
			}
		}
		
		isSet = false;
		
		//Diagonal _-
		tempX = posX;

		for (int i = posY + 1; i < y; i++) {
			if (tempX-- == -1) break;

			if (table[i][tempX] == opponentStone) {
				table[i][tempX] = possibleReverseChar;
				isSet = true;
				continue;
			}
			if (isSet && table[i][tempX] == stone) {
				replaceReverse(stone);
				break;
			}
			if (table[i][tempX] == '.') {
				replaceReverse(opponentStone);
				break;
			}
			
		}
		isSet = false;
		//Diagonal -_
		tempX = posX;

		for (int i = posY + 1; i < y; i++) {
			if (tempX++ == x) break;

			if (table[i][tempX] == opponentStone) {
				table[i][tempX] = possibleReverseChar;
				isSet = true;
				continue;
			}
			if (isSet && table[i][tempX] == stone) {
				replaceReverse(stone);
				break;
			}
			if (table[i][tempX] == '.') {
				replaceReverse(opponentStone);
				break;
			}

		}
		isSet = false;
		//Diagonal `-
		tempX = posX;

		for (int i = posY - 1; i >= 0; i--) {
			if (tempX-- == -1) break;

			if (table[i][tempX] == opponentStone) {
				table[i][tempX] = possibleReverseChar;
				isSet = true;
				continue;
			}
			if (isSet && table[i][tempX] == stone) {
				replaceReverse(stone);
				break;
			}
			if (table[i][tempX] == '.') {
				replaceReverse(opponentStone);
				break;
			}
		}
		
		isSet = false;
		//Diagonal -`
		tempX = posX;

		for (int i = posY - 1; i >= 0; i--) {
			if (tempX++ == x) break;

			if (table[i][tempX] == opponentStone) {
				table[i][tempX] = possibleReverseChar;
				isSet = true;
				continue;
			}
			if (isSet && table[i][tempX] == stone) {
				replaceReverse(stone);
				break;
			}
			if (table[i][tempX] == '.') {
				replaceReverse(opponentStone);
				break;
			}

		}
		
		
	}
	void replaceReverse(char stone) {
		

		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (table[i][j] == '-') {
					table[i][j] = stone;
				}
			}
		}
	}
	void findLegalMoves(char stone) {
		char opponentStone;
		if (stone == 'x') opponentStone = 'o';
		else opponentStone = 'x';
		clearLegalMoves();
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (table[i][j] == stone) {
					checkLegalMoves(i, j, opponentStone, stone);
				}
			}
		}
	}
	void checkLegalMoves(int posY, int posX, char opponentStone, char stone) {
		bool isSet = false;
		int tempX;
		int tempY;
		char legalMove = '*';
		
		// X
		for (int i = posX; i < x; i++) {
			if (table[posY][i] == opponentStone) {

				isSet = true;
				continue;
			}
			if (isSet && table[posY][i] == stone) {
				break;
			}
			if (isSet) {
				table[posY][i] = legalMove;
				isSet = false;
				break;
			}
		}

		isSet = false;

		for (int i = posX; i >= 0; i--) {
			if (table[posY][i] == opponentStone) {
				isSet = true;
				continue;
			}
			if (isSet && table[posY][i] == stone) {
				break;
			}
			if (isSet) {
				table[posY][i] = legalMove;
				isSet = false;
				break;
			}
		}
		isSet = false;
		
		// Y
		for (int i = posY; i < y; i++) {
			if (table[i][posX] == opponentStone) {
				isSet = true;
				continue;
			}
			if (isSet && table[i][posX] == stone) {
				break;
			}
			if (isSet) {
				table[i][posX] = legalMove;
				isSet = false;
				break;
			}
		}

		isSet = false;

		for (int i = posY; i >= 0; i--) {
			if (table[i][posX] == opponentStone) {
				isSet = true;
				continue;
			}
			if (isSet && table[i][posX] == stone) {
				break;
			}
			if (isSet) {
				table[i][posX] = legalMove;
				isSet = false;
				break;
			}
		}

		
		isSet = false;
		
		//Diagonal -_
		tempX = posX;

		for (int i = posY + 1; i < y; i++) {
			if (tempX++ == x) break;
			if (table[i][tempX] == opponentStone) {
				isSet = true;
				continue;
			}
			if (isSet && table[i][tempX] == stone) {
				break;
			}
			if (isSet) {
				table[i][tempX] = legalMove;
				isSet = false;
				break;
			}
		}
		isSet = false;

		//Diagonal _-
		tempX = posX;

		for (int i = posY + 1; i < y; i++) {
			if (tempX-- == -1) break;
			if (table[i][tempX] == opponentStone) {
				isSet = true;
				continue;
			}
			if (isSet && table[i][tempX] == stone) {
				break;
			}
			if (isSet) {
				table[i][tempX] = legalMove;
				isSet = false;
				break;
			}
		}

		isSet = false;

		
		//Diagonal -`
		tempX = posX; 

		for (int i = posY-1; i >= 0; i--) {
			if (tempX++ == x) break;
			
			if (table[i][tempX] == opponentStone) {
				isSet = true;
				continue;
			}
			if (isSet && table[i][tempX] == stone) {	
				break;
			}
			if (isSet) {
				table[i][tempX] = legalMove;
				isSet = false;
				break;
			}
		}


		isSet = false;

		//Diagonal `-
		tempX = posX;

		for (int i = posY - 1; i >= 0; i--) {
			if (tempX-- == -1) break;
			if (table[i][tempX] == opponentStone) {
				isSet = true;
				continue;
			}
			if (isSet && table[i][tempX] == stone) {
				break;
			}
			if (isSet) {
				table[i][tempX] = legalMove;
				isSet = false;
				break;
			}
		}
		
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	char** getTable() {
		return table;
	}
private:
	int x, y;
	int realX, realY;
	char** table;
	void initTable() {
		int startPointX = x / 2 - 1 ;
		int startPointY = y / 2 - 1;
		char* headerX = new char();
		char* headerY = new char();

		char stone = 'x';

		table = new char* [x+2];
		for (int i = 0; i < x+1; i++) {
			table[i] = new char[y+2];
			for (int j = 0; j < y+1; j++) { 
				table[i][j] = '.';
			}
		}
		for (int i = 0; i < x + 1; i++) {
			_itoa_s(i, headerY, 2, 10);
			table[i][y] = headerY[0];
			for (int j = 0; j < y + 1; j++) {
				_itoa_s(j, headerX, 2, 10);
				table[x][j] = headerX[0];
			}
		}

		
		
		table[startPointX][startPointY] = 'x';
		table[startPointX+1][startPointY] = 'o';
		table[startPointX+1][startPointY+1] = 'x';
		table[startPointX][startPointY+1] = 'o';
		
	}
};

