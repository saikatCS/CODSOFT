/*
 * Developer  : Saikat Acharjee
 * Project: TIC-TAC-TOE GAME
 * Description: A simple console-based Tic-Tac-Toe game that allows two players to play against each other
 * Player1 Represent: X  |  Player2 Represent: O
 */

#include <iostream>
#include <limits>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

// Function to reset the board before each new game
void resetBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = num++;
}

void displayBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n\n";
}

bool makeMove(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    return (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
           (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer);
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame() {
    int move;
    bool gameOver = false;

    resetBoard(); // initialize board
    currentPlayer = 'X';

    cout << "\t\t\t\t\t\tTic-Tac-Toe Game (2 Players)\n";
    cout << "\t\t\t\t\t\t----------------------------\n";
    cout << "\t\t\t\t\tPlayer1 Represent: X  |  Player2 Represent: O\n";
    cout << "\t\t\t\t\t---------------------------------------------\n";

    cout << "Press 2times Enter to start the game...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    while (!gameOver) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        if (!makeMove(move)) {
            cout << "That spot is already taken. Try again.\n";
            continue;
        }

        if (checkWin()) {
            displayBoard();
            cout << " Congratulations Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } else if (checkDraw()) {
            displayBoard();
            cout << " It's a draw!\n";
            gameOver = true;
        } else {
            switchPlayer();
        }
    }
}

int main() {
    char playAgain;
    
    // Game Continuty //
    do {
        playGame();

        cout << "\nDo you want to play another game? (Y/N): ";
        cin >> playAgain;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (playAgain == 'Y' || playAgain == 'y');

    return 0;
}

