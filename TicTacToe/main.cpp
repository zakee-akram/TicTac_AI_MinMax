#include <iostream>
void makeBoard();
char board[3][3] = { {'#','#','#'},{'#','#','#'},{'#','#','#'} };
int main(){
    makeBoard();
}

void makeBoard() {
    //Make Board For Game through console; 
    std::cout << "Player 1 = 'X'    Player 2 = 'O'" << std::endl;
    std::cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "| \n";
    std::cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "| \n";
    std::cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "| \n";
} 