#include "GamePlay.h"
#include<string>
#include "Board.h"
#include <iostream>
#include <conio.h>
#include <thread>

using namespace std;
static char nextMove;

///////////////////// CHALLENGE ACCEPTED BY AVIAD !!!


void  getInputFromUser(){
	nextMove = _getch();
}
   
int menu(){
	int choice;
	cout << "###################################" << endl;
	cout << "#######--" << "CHOOSE YOUR STYLE" << "--#######" << endl;
	cout << "1 - Classic Game" << endl;
	cout << "2 - Suprise Game - only for brave people !" << endl;
	cout << "###################################" << endl;
	cout << "###### USE w,a,s,d keys only! #####" << endl;
	cout << "Enter Your Choice ";
	cin >> choice;
	return  choice;
}

void main(){

	Board *board = new Board();
	thread *t;
	char move;
	string name;
	int choice = menu();
	if (choice == 2)
	{
		cout << "Please enter your name ";
		cin >> name;
		board->initCuriosString(name);
	}
	board->printBoard();
	move = _getch();           
	nextMove = move;

	try{
		while (true){

			move = nextMove;
			while (move == nextMove){
				t = new thread(getInputFromUser);   // waiting for user input for move
				board->makeMove(move);
				board->printBoard();
				this_thread::sleep_for(chrono::milliseconds(board->getLevelDelay()));
				if (nextMove != move){            //time to change direction , static char 'nextMove' was changed
					move = nextMove;
				}
				t->detach();
				delete t;
				system("cls");
			}


		}

	}
	catch (gameOverExp s){
		cout << s.what() << endl;
	}
	delete board;
	system("PAUSE");
	
}