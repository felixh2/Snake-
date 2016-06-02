#include"Board.h"



Board::Board()
{
	initBoard();
	srand(time(NULL));
	levelDelay = 80;
}

void Board::initBoard(){

	for (int i = 0; i < LENGTH; i++){
		for (int j = 0; j < WIDTH; j++){
			if (i == 0 || i == LENGTH - 1 || j == 0 || j == WIDTH-1)
				board[i][j] = '#';
			else
				board[i][j] = ' ';
		}
	}
	coorX.push_back(posX);
	coorY.push_back(posY);
	board[posY][posX] = 'O';
	board[StarPosY][StarPosX] = '*';
	

}

void Board::makeMove(char &move)
{
	 tailCoorX = coorX.back();
	 tailCoorY = coorY.back();
	 

	switch (move)
	{
	case 'w':                 // move up
		//cout << "Up"<< endl;
		posY = posY - 1;
		break;
	case 's':                 // move down
		//cout << "Down" << endl;
		posY = posY + 1;
		break;
		
	case 'a':                 // move left
		//cout << "Left" << endl;
		posX = posX - 1;
		break;
	case 'd':                 // move right
		//cout << "Right" << endl;
		posX = posX + 1;
		break;
	
	}
	
	updateBoard();

}
void Board::updateBoard() throw (gameOverExp){

	for (int i = coorX.size() - 1; i > 0; i--){  //           updating the move
		coorX[i] = coorX[i - 1];
		coorY[i] = coorY[i - 1];
	}
	coorX[0] = posX;
	coorY[0] = posY;
	if (mode == 0){
		for (int i = 0; i < coorX.size(); i++){
			board[coorY[i]][coorX[i]] = 'O';
		}
	}
	else{
		for (int i = 0; i < coorX.size(); i++){
			board[coorY[i]][coorX[i]] = str.at(i);
		}
	}
		board[tailCoorY][tailCoorX] = ' ';

		if (coorX[0] == StarPosX && coorY[0] == StarPosY){
			addLinkToSnake();
			setStarPos();
		}
		if (coorX[0] == 0 || coorX[0] == WIDTH - 1 || coorY[0] == 0 || coorY[0] == LENGTH - 1) // getting stuck in the wall
			throw gameOverExp("GAME OVER - WALL COLISSION !");

		for (int i = 1; i < coorX.size(); i++)
			if (posX == coorX[i] && posY == coorY[i])
				throw gameOverExp("GAME OVER - DON'T HIT YOURSELF !");

	}


Board::~Board()
{
}

void Board::printBoard(){

	for (int i = 0; i < LENGTH; i++){
		for (int j = 0; j < WIDTH; j++){
				cout << board[i][j];		
		}cout << endl;
	}
}


void Board::addLinkToSnake()
{
	//
	numOfLinks++;
	levelDelay = levelDelay - 3;
	coorX.push_back(tailCoorX);
	coorY.push_back(tailCoorY);
	
}
void Board :: setStarPos()
{
	// random function generator
	StarPosY = (rand() % 14 + 1); // 30
	StarPosX = (rand() % 25 + 1);   // 16
	//cout << "randX : " << StarPosX << " randY : " << StarPosY << endl;
	board[StarPosY][StarPosX] = '*';
}


int  Board::getLevelDelay()
{
	return levelDelay;
}

void Board::initCuriosString(string name)
{
	mode = 1;
	str = "O-" + name + "-YOU-R-GREAT-OOOOOO";
}