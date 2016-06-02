#ifndef _Board_H
#define _Board_H

#include <iostream>
#include "gameOverExp.h"
#include <stdlib.h>
#include <time.h> 
#include <thread>
#include <conio.h>
#include<vector>

#define WIDTH 30
#define LENGTH 16
using namespace std;

class Board
{
public:
	Board();
	~Board();
	void printBoard();
	void makeMove(char & move);
	void setStarPos();
	int getLevelDelay();
	void initCuriosString(string);
	
private:
	void initBoard();
	
	void updateStarPos();
	void updateBoard() throw(gameOverExp);
	void setSnakyInitPos();
	void addLinkToSnake();
	int mode = 0;
	int levelDelay;
	bool gotStar = false;
	char board[LENGTH][WIDTH];
	vector<int> coorX;
	vector<int> coorY;
	int tailCoorX = 10;
	int tailCoorY = 10;
	int numOfLinks = 0;
	string str = " ";
	char star = '*';
	 int posX = 2;
	 int posY = 5;
	 int StarPosX = 3;
	 int StarPosY = 5;
	 int score = 0;
	 int tempX;
	 int tempY;
};



#endif