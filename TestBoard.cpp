//File name: /Users/laptopuser/Documents/cs135_codes/projects/game1024/TestBoard.cpp
#include <iostream>
#include "Board.hpp"
using namespace std;


int main()
{
    //Board game; //create a default Board object game
    //game.print(); //test print method of game

    //Board game2(4);
       //create a Board object with four rows
       //and four columns
    //game2.print(); //test print method of game2

    Board game3(3, 3);
       //create a Board object with three rows
       //and four columns
    game3.print(); //test print method of game3
    game3.start();

    return 0;
}

