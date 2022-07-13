#include <iostream>
#include<iomanip>

using namespace std;

//global variables
string player1name;
string player2name;

string players[2];

bool gameOver;

int userColumn = 1;
int userRow = 1;
//int tmp = 0;

int turnCount = 0;

char gameBoard[3][3];
char pieces[2] = {'X','O'};


//checks if spot that user wants to play in is filled or not
bool canPlay(int col, int row){
    if (gameBoard[col][row] == '-'){
        return true;
    }
    else {
        return false;
    }
}


bool didWin (char board[3][3]) {
    if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2]== 'X' || board[0][0] == 'O' && board[0][1] == 'O' && board[0][2]== 'X') {
        return true;
    }else if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X' || board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O'){
        return true;
    }else if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X' || board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') {
        return true;
    }



    if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X' || board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O'){

        return true;
    }else if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X' || board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O'){

        return true;
    }else if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X' || board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'){
        return true;
    }

    if(board[0][0] == 'X' && board[1][1] == 'X' &&board[2][2] == 'X' || board[0][0] == 'O' && board[1][1] == 'O' &&board[2][2] == 'O' ){
        return true;
    }else{
        return false;
    }
}



//prints board out
void printBoard(){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout<<setw(2)<<gameBoard[i][j]<<" ";
        }
        cout<<endl;
    }

}



int main() {

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            gameBoard[i][j] = '-';
        }
    }


    gameOver = false;

    cout << "Welcome to the game of tic-tac-toe" << endl << "Enter '0' to quit" << endl;

    cout << "Enter Player 1 Name (X): ";
    cin >> player1name;
    player1name = player1name  + " (X)";
    players[0]=player1name;
    cout << "Hello " << player1name << "!" << endl;

    cout << "Enter Player 2 Name (O): ";
    cin >> player2name;
    player2name=player2name+" (O)";
    players[1]=player2name;
    cout << "Hello " << player2name << "!" << endl;

    cout << "Lets Get Started" << endl;

    do {
        cout << players[turnCount%2] << "'s turn" << std::endl;
        cout << "Current Game Board:" << std::endl;
        printBoard();
        cout << "Enter Row: ";
        cin >> userRow;
        cout << "Enter Column:";
        cin >> userColumn;

        if(userRow == 0){
            exit(0);
        }

        while(!canPlay(userColumn - 1, userRow - 1)) {
            cout<<"Invalid Choice Please Choose again"<<endl;
            cout<<"Enter Row: ";
            cin>>userRow;
            cout<<"Enter Column:";
            cin>>userColumn;
        }


        gameBoard[userColumn-1][userRow-1] = pieces[turnCount%2];

        turnCount++;
        gameOver=didWin(gameBoard);

    } while (!gameOver && userRow != 0 && userColumn != 0 && turnCount < 9);

    printBoard();
    gameOver = didWin(gameBoard);

    if(gameOver){
        std::cout << players[(turnCount+1)%2] << "'s win!" << std::endl;
        std::cout << "Game won after " << turnCount << " Turns" << std::endl;
    }
    else{
        std::cout << "Game ended in Draw" << std::endl;
    }

    return 0;
}
