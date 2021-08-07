#include <iostream>
void makeBoard();
int checkIfWon();
void playgame();
bool playsLeft();
void prompt();
char board[3][3] = { {'#','#','#'},{'#','#','#'},{'#','#','#'} };
char player = 'X';
char machine = 'O';
//Variable that controls who turn it is. True means player, false means machine. 
bool turn;
void move();
int minMax();
void bestMove(int row, int column);
int main() {
    makeBoard();
    board[0][0] = machine;
   /* board[0][1] = player;*/
    playgame();
}
void prompt() {
    std::cout << "Enter Row: \n";
    int userRow;
    std::cin >> userRow;
    std::cout << "Enter Column \n";
    int userColumn;
    std::cin >> userColumn;
    if (board[userRow - 1][userColumn - 1] == '#') {
        std::cout << "OK\n";
        board[userRow - 1][userColumn - 1] = machine;
        makeBoard();
        turn = false;
        move();
    }
}
void playgame() {
    int number = 1;
    if (number == 1) {
        turn = true;
        prompt();
    }
    else {
        turn = false;
        move();
    }
}
void makeBoard() {
    //Make Board For Game through console; 
    std::cout << "Player 1 = 'X'    Player 2 = 'O'" << std::endl;
    std::cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "| \n";
    std::cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "| \n";
    std::cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "| \n";

    /*std::cout << "////////////////////////////////////////////////////////////////////\n";
    std::cout << "1" << "|" << "2" << "|" << "3\n";
    std::cout << "4" << "|" << "5" << "|" << "6\n";
    std::cout << "7" << "|" << "8" << "|" << "9\n";*/

}
bool playsLeft() {
    for (int i = 0; i < 3; i++) {
        for (int x = 0; i < 3; i++) {
            if (board[i][x] == '#') {
                return true;
            }
        }
    }
    return false;
}
void move() {
    int flag = checkIfWon();
    switch (flag)
    {
    case 1:
        std::cout << "Player Has One!!!";
        return;
    case -1:
        std::cout << "Machine Has One!!!";
        return;
   /* case 0:
        std::cout << "Game Ended In Tie!!!";
        return;*/
   /* default:
        std::cout << "ERROR";*/
    }

    if (playsLeft) {
        if (turn) {
            prompt();
        }
        else {
            int row =0 , column =0 ;
            bestMove(row, column);

        }
    }
}
void bestMove(int row, int column) {
    int best = -1000;
    row,column = -1;
    for (int i = 0; i < 3; i++) {
        for (int y = 0; y < 3; y++) {
            if (board[i][y] == '#') {
                board[i][y] = player;
                int moveVal = minMax();
                
                board[i][y] = '#';
                if (moveVal > best)
                {
                    row = i;
                    column = y;
                    best = moveVal;
                }
            }
        }
    }
    std::cout << "Should Do " << best << row << column;
}
int minMax() {
    if (turn == false) {
        int max = -1000;
        for (int i = 0; i < 3; i++) {
            for (int y = 0; y < 3; y++) {
                if (board[i][y] == '#') {
                    board[i][y] = machine;
                    !turn;
                    max = std::max(max, minMax());
                    board[i][y] = '#';
                }
            }
        }
        return max;
    }
    if (turn == true) {
        int max = 1000;
        for (int i = 0; i < 3; i++) {
            for (int y = 0; y < 3; y++) {
                if (board[i][y] == '#') {
                    board[i][y] = player;
                    !turn;
                    max = std::max(max, minMax());
                    board[i][y] = '#';
                }
            }
        }
        return max;
    }
}
int checkIfWon() {
    //Check if row has won.
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if (board[row][0] == player) {
                return 1;
            }
            else if (board[row][0] == machine)
            {
                return -1;
            }
        }
    }
    //Check if column has won.
    for (int row = 0; row < 3; row++) {
        if (board[0][row] == board[1][row] && board[1][row] == board[2][row]) {
            if (board[0][row] == player) {
                return 1;
            }
            else if (board[0][row] == machine)
            {
                return -1;
            }
        }
    }
    //Check if diagonal has won.
    if (board[1][1] == board[0][0] && board[1][1] == board[2][2]) {
        if (board[1][1] == player) {
            return 1;
        }
        else if (board[1][1] == machine) {
            return -1;
        }
    }
    if (board[1][1] == board[0][2] && board[1][1] == board[2][0]) {
        if (board[1][1] == player) {
            return 1;
        }
        else if (board[1][1] == machine) {
            return -1;
        }
    }
    return 0;
}