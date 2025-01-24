#include <iostream>
#include <vector>
using namespace std;
void printBoard(const vector<vector<char>>& board) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "--+---+--\n";
    }
    cout << "\n";
}
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||  
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) { 
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) { 
        return true;
    }
    return false;
}
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; 
            }
        }
    }
    return true; 
}
void playerMove(vector<vector<char>>& board, char player) {
    int move;
    while (true) {
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;
        move--; 
        int row = move / 3;
        int col = move % 3;
        if (move >= 0 && move < 9 && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            cout << "That slot is already used." << endl;
        }
    }
}
void playGame() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); 
    char currentPlayer = 'X';
    bool gameOver = false;

    while (!gameOver) {
        printBoard(board);
        playerMove(board, currentPlayer);
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        } else if (checkDraw(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            gameOver = true;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}
int main() {
    char playAgain;
    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        cin.ignore();
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "See you later. Thanks for playing!" << endl;
    return 0;
}
