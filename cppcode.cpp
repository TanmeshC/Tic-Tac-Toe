#include <iostream>
#include <graphics.h>

using namespace std;

int board[3][3]; // Tic-Tac-Toe board: 0 for empty, 1 for 'X', 2 for 'O'
int currentPlayer = 1; // Player 1 is 'X', Player 2 is 'O'

// Function to draw the Tic-Tac-Toe board
void drawBoard() {
    cleardevice(); // Clear screen
    
    // Draw the grid
    line(200, 100, 200, 400);
    line(300, 100, 300, 400);
    line(100, 200, 400, 200);
    line(100, 300, 400, 300);
    
    // Draw 'X' and 'O' on the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int x = 150 + j * 100;
            int y = 150 + i * 100;
            if (board[i][j] == 1) { // Draw 'X'
                line(x - 30, y - 30, x + 30, y + 30);
                line(x + 30, y - 30, x - 30, y + 30);
            } else if (board[i][j] == 2) { // Draw 'O'
                circle(x, y, 30);
            }
        }
    }
}

// Function to check for a winner or draw
int checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0)
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0)
            return board[0][i];
    }
    
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0)
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0)
        return board[0][2];
    
    // Check if there's a draw (board full)
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == 0)
                return 0; // Game is not over
    
    return 3; // It's a draw
}

// Function to handle player moves
void playerMove(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == 0) {
        board[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == 1) ? 2 : 1; // Switch players
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Initialize the board
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = 0;

    // Main game loop
    while (true) {
        drawBoard();
        
        // Check if there's a winner
        int result = checkWinner();
        if (result == 1) {
            outtextxy(150, 450, (char*)"Player 1 (X) wins!");
            break;
        } else if (result == 2) {
            outtextxy(150, 450, (char*)"Player 2 (O) wins!");
            break;
        } else if (result == 3) {
            outtextxy(150, 450, (char*)"It's a draw!");
            break;
        }

        // Input row and column using keyboard
        char key = getch();
        if (key == '1') playerMove(0, 0);
        else if (key == '2') playerMove(0, 1);
        else if (key == '3') playerMove(0, 2);
        else if (key == '4') playerMove(1, 0);
        else if (key == '5') playerMove(1, 1);
        else if (key == '6') playerMove(1, 2);
        else if (key == '7') playerMove(2, 0);
        else if (key == '8') playerMove(2, 1);
        else if (key == '9') playerMove(2, 2);
    }

    // Wait for user to close the game
    getch();
    closegraph();

    return 0;
}




/*1' -> Top-left corner
'2' -> Top-center
'3' -> Top-right
'4' -> Middle-left
'5' -> Middle-center
'6' -> Middle-right
'7' -> Bottom-left
'8' -> Bottom-center
'9' -> Bottom-right*/
