#include <stdio.h>

#define SIZE 3

//mohammad ali nasiri
//404149076
//github------> harvagt internet vasl shavad upload mikonam

typedef struct {
    char board[SIZE][SIZE];   //takte baraye nemayesh
    char currentPlayer;       //tashkhis nobat bazikon 
    int moveCount;            // shomaresh tedad hare cat
    int gameOver;             // 0 = edame , 1 = payan
}dooz;

dooz game;

void startGame() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            game.board[i][j] = ' ';
        }
    }
    game.currentPlayer = 'X';
    game.moveCount = 0;
    game.gameOver = 0;
}

void printBoard() {
    int i, j;

    printf("\n   1   2   3\n");//namayesh shomare setoon
    for (i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);//namayesh shomare satr
        for (j = 0; j < SIZE; j++) {
            printf(" %c ", game.board[i][j]);
            if (j < SIZE-1){
			printf("|");}
        }
        printf("\n");
        if (i < SIZE-1)
            printf("  ---+---+---\n");
    }
    printf("\n");
}

int checkWin(char player) {
    int i;

    // barrasi satr va setoon ha ke bebinim kasi barandeh shode ya na
    for (i = 0; i < SIZE; i++) {
        if (game.board[i][0] == player &&
            game.board[i][1] == player &&
            game.board[i][2] == player)
            return 1;

        if (game.board[0][i] == player &&
            game.board[1][i] == player &&
            game.board[2][i] == player)
            return 1;
    }

    if (game.board[0][0] == player &&
        game.board[1][1] == player &&
        game.board[2][2] == player)
        return 1;

    if (game.board[0][2] == player &&
        game.board[1][1] == player &&
        game.board[2][0] == player)
        return 1;

    return 0;
}

void switchPlayer() {
    if (game.currentPlayer == 'X'){
        game.currentPlayer = 'O';}
    else{
        game.currentPlayer = 'X';}
}

void playerMove() {
    int row, col;

    while (1) {
        printf("Player %c is turn\n", game.currentPlayer);
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);

        // vorodi na motabar
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input! Please enter numbers between 1 and 3.\n\n");
            continue;
        }

        row--; 
        col--;

        if (game.board[row][col] != ' ') {
            printf("This cell is already occupied!\n\n");
            continue;
        }

        // harekat gabel gabool
        game.board[row][col] = game.currentPlayer;
        game.moveCount++;
        break;
    }
}

void checkGameStatus() {
    if (checkWin(game.currentPlayer)) {
        printBoard();
        printf("Player %c wins!\n", game.currentPlayer);
        game.gameOver = 1;
    } 
    else if (game.moveCount == 9) {
        printBoard();
        printf("The game is a draw!\n");
        game.gameOver = 1;
    }
}

int main() {
    char again;

    while (1) {
        startGame();

        while (!game.gameOver) {
            printBoard();
            playerMove();
            checkGameStatus();
            if (!game.gameOver)
                switchPlayer();
        }

        printf("\Do you want to play again? (y/n): ");
        scanf(" %c", &again);

        if (!(again == 'y' || again == 'Y')) {
            break; 
        }
    }

    printf("\nGoodbye ;)\n");
    return 0;
}