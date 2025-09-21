#include<iostream>

using namespace std;

void printGrid(char grid[3][3]) {
    cout << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "|" << grid[i][j] << "|";
        }
        cout << endl;
    }

    cout << endl;
}

bool isMoveLegal(int rowPosition, int columnPosition, char grid[3][3]) {
    if (rowPosition < 0 || rowPosition > 2 || columnPosition < 0 || columnPosition > 2 ) {
        return false;
    }
    
    if (grid[rowPosition][columnPosition] == ' ') {
        return true;
    }

    return false;
}

char checkWinningCharacter(char grid[3][3]) {
    // Check diagonally
    if (grid[0][0] != ' ') {
        if (grid[0][0] == grid [1][1] && grid[1][1] == grid[2][2]) {
            return grid[0][0];
        }
    }

    // Check diagonally (reverse)
    if (grid[0][2] != ' ') {
        if (grid[0][2] == grid [1][1] && grid[1][1] == grid[2][0]) {
            return grid[0][2];
        }
    }

    // Check rows
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == ' ') {
            continue;
        }
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
            return grid[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (grid[0][i] == ' ') {
            continue;
        }
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
            return grid[0][i];
        }
    }

    return ' ';
}

int main() {
    char grid[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };

    bool gameOver = false;
    int currentPlayer = 1;
    char currentPlayerSymbol = ' ';

    while (!gameOver) {
        if (currentPlayer == 1) {
            currentPlayerSymbol = 'x';
        } else {
            currentPlayerSymbol = 'o';
        }

        printGrid(grid);

        printf("It's player %d's turn. \n", currentPlayer);

        int rowPosition = 0;
        int columnPosition = 0;

        cout << "Enter row position: ";
        cin >> rowPosition;

        cout << "Enter column position: ";
        cin >> columnPosition;

        if (!isMoveLegal(rowPosition, columnPosition, grid)) {
            cout << "You can't play this position. Choose a valid one. \n";
            continue;
        }

        grid[rowPosition][columnPosition] = currentPlayerSymbol;

        if (checkWinningCharacter(grid) == currentPlayerSymbol) {
            printf("Player %d has won. \n", currentPlayer);
            gameOver = true;
        }
        
        if (currentPlayer == 1) {
            currentPlayer = 2;
        } else {
            currentPlayer = 1;
        }
    }

    printGrid(grid);

    return 0;
}