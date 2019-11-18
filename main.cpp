#include <iostream>
#include <cstdlib>
#include "TicTacToe.h"

using namespace std;

int main()
{
    //variable declaration
    short board[3][3] = {0};
    short _count = 0;
    //current player
    Player player = PlayerO;

    //display board for first time
    display(board);

    //start a infinite loop here
    while(true)
    {
        //get user input
        getInput(player,board);

        //increase _count here
        _count++;

        //clear previous screen
        system("cls");

        //display new board
        display(board);

        //if _count is 5 or more means there is a possibility of player's win
        if(_count >= 5)
        {
            //get winner
            Player p = getWinner(board);

            //check winner if it is not none
            if(p != 0)
            {
                std::cout<<"\nPlayer "<<toChar(p)<<" won."<<std::endl;
                break;
            }
        }

        //if _count == 9 means either win(in previous statement) or draw
        if(_count == 9)
        {
            std::cout<<"Match is draw."<<std::endl;
            break;
        }
    }

    //pause the screen
    system("pause");
    return 0;
}














