#include "TicTacToe.h"
#include <iostream>
#include <limits>

/**
to get X,O,space
@params
int x;
*/
char toChar(int x)
{
    if(x == 0)
        return ' ';
    else if(x == 1)
        return 'O';
    else
        return 'X';
}


/**
get user input
@params
Player &player;//to change player after every run used reference
short board[3][3];//to change value and get value from board
*/
void getInput(Player &player,short board[3][3])
{
    int x = 0;
    std::cout<<"Player "<<((player == PlayerO)?('O'):('X'))<<"'s term : ";
    do{
    std::cin>>x;

    //if user enters non-digit number
    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Entered non-digit value enter, input again  : ";
    }

    //if input value out of range
    else if(x < 0 || x > 10)
        std::cout<<"Input must be 1-9, input valid number again : ";

    //check if input is already used
    else if(!check(x-1,board))
        std::cout<<"Input has been already used, input again    : ";

    //else user entered a valid input so break loop
    else
        break;
    }while(true);

    //as user will enter 1 to 9 so decrease by one as array starts with 0
    x--;

    //if x = 7 then x/3 = 2 and x%3 = 1 board[2][3]
    board[x/3][x%3] = player;

    //swap value X-O of player
    if(player == PlayerO)
        player = PlayerX;
    else
        player = PlayerO;
}

/**
to display board
@params
short board[3][3];
*/
void display(short board[3][3])
{
        std::cout<<toChar(board[0][0])<<" | "<<toChar(board[0][1])<<" | "<<toChar(board[0][2])<<std::endl;
        std::cout<<"--|---|--"<<std::endl;
        std::cout<<toChar(board[1][0])<<" | "<<toChar(board[1][1])<<" | "<<toChar(board[1][2])<<std::endl;
        std::cout<<"--|---|--"<<std::endl;
        std::cout<<toChar(board[2][0])<<" | "<<toChar(board[2][1])<<" | "<<toChar(board[2][2])<<std::endl;
}

/**
to get winner
it will return 1 for PlayerO and 2 for PlayerX
and 0 for none
@params
short board[3][3]; //board containing data
*/
Player getWinner(short board[3][3])
{
    //check for rows
    for(int i = 0; i < 3; i++)
        if(board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][1];

    //check for columns
    for(int i = 0; i < 3; i++)
        if(board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[1][i];

    //check for corners top-left to bottom-right
    if(board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[1][1];

    //check for corners top-right to bottom-left
    if(board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[1][1];

    //if no winner return none
    return 0;
}


/**
to check if place is already used
@params
int x;//x should not be negative or greater than or equal to 9
short board[3][3];//board containing data
*/
bool check(int x,short board[][3])
{
    if(board[x/3][x%3] == 0)
        return true;
    else return false;
}

