#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentMarker;
int currentPlayer;

void drawBoard() {
    cout << "Current board state:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "--|---|--\n";
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / SIZE;
    int col = (slot - 1) % SIZE;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}

int winner() {
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return currentPlayer;
    return 0;
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X') currentMarker = 'O';
    else currentMarker = 'X';
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

int main() {
    cout << "Welcome to Tic Tac Toe!\n";
    cout << "Player 1, choose your marker: ";
    char markerP1;
    cin >> markerP1;

    currentPlayer = 1;
    currentMarker = markerP1;

    drawBoard();
    
    int playerWon = 0;
    for (int i = 0; i < SIZE * SIZE; ++i) {
        cout << "Player " << currentPlayer << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Choose a slot between 1 and 9.\n";
            --i;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already occupied! Try again.\n";
            --i;
            continue;
        }

        drawBoard();
        playerWon = winner();

        if (playerWon == 1) {
            cout << "Player 1 wins!\n";
            break;
        } else if (playerWon == 2) {
            cout << "Player 2 wins!\n";
            break;
        }

        swapPlayerAndMarker();
    }

    if (playerWon == 0) cout << "It's a tie!\n";

    return 0;
}