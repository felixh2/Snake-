#pragma once


#include<exception>
#include <string>
using namespace std;
class gameOverExp : public exception
{

public:
	gameOverExp(string msg);

};