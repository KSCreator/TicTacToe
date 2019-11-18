#ifndef TICTACTOE_H
#define TICTACTOE_H


//player declaration it will make code more readable
#define Player int
#define PlayerO 1
#define PlayerX 2

/**
get user input
@params
Player &player;//to change player after every run used reference
short board[3][3];//to change value and get value from board
*/
void getInput(Player &p,short board[3][3]);


/**
to display board
@params
short board[3][3];//board to display
*/
void display(short board[3][3]);


/**
to get winner
it will return 1 for PlayerO and 2 for PlayerX
and 0 for none
@params
short board[3][3];//board containing data
*/
Player getWinner(short board[3][3]);


/**
to check if place is already used
@params
int x;//x should not be negative or greater than or equal to 9
short board[3][3];//board containing data
*/
bool check(int x,short board[3][3]);


/**
to get X,O,space
@params
int x;
*/
char toChar(int x);


#endif // TICTACTOE_H
