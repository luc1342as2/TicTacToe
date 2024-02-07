//Lucas Ghigli
//2023/10/15
//Tic-Tac-Toe game

#include <stdio.h>

#define SIZE 3

//Creation of the table for Tic Tac Toe.
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("-----------\n");
        }
    }
    printf("\n");
}

int isMoveValid(char board[SIZE][SIZE], int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ');
}

int isGameOver(char board[SIZE][SIZE]) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return 1; // Game over, it tells which player won.
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return 1; // Game over, it tells which player won.
    }

    // Check for a tie
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; // There is an empty space, the game is not over yet
            }
        }
    }

    return -1; // It's a tie, in case both players are unable to win.
}

int main() {
    char board[SIZE][SIZE];
    int row, col, currentPlayer = 1;

    initializeBoard(board);

    do {
        printBoard(board);

        currentPlayer = (currentPlayer == 1) ? 2 : 1;

        printf("Player %d, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (isMoveValid(board, row, col)) {
            board[row][col] = (currentPlayer == 1) ? 'X' : 'O';
        } else {
            printf("Invalid move. Try again.\n");
            currentPlayer = (currentPlayer == 1) ? 2 : 1; // Retry for the same player
        }

    } while (!isGameOver(board));

    printBoard(board);

    if (isGameOver(board) == 1) {
        printf("Player %d wins!\n", currentPlayer);
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}
