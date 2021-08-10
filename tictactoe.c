//A Simple TicTacToe Game

#include<stdio.h>

char board[3][3];
char new = 'y';
char p1[10], p2[10], winner[10]; 

void setNames(void)
{
    printf("Enter player 1's name: ");
    scanf("%s", p1);
    printf("Enter player 2's name: ");
    scanf("%s", p2);
}
void displayBoard(void)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}
void resetBoard(void)
{
    if (p1[0] == 0 || p2[0] == 0)
        setNames();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '-';
        }
    }
    printf("\nBoard Reset!\n");
    winner[0] = 0;
}
void move(char *player)
{
    int x, y;
    printf("%s, enter the coordinates of your move (x y): ", player);
    scanf("%d %d", &x, &y);
    x--; y--;
    if (board[x][y] == '-')
    {
        if (player == p1)
            board[x][y] = 'X';
        else if (player == p2)
            board[x][y] = 'O';
    }
    else
    {
        displayBoard();
        printf("Wrong move! The block is either filled or out of the board. Try again.\n");
        move(player);
    }
}
int isFilled(void)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
            {
                return 0;
            }
        }
    }
    return 1;
}
int gameOver(void)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
        {
            for (int j = 0; j < 10; j++) winner[j] = p1[j];
            return 1;
        }
        if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
        {
            for (int j = 0; j < 10; j++) winner[j] = p2[j];
            return 1;
        }
        if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
        {
            for (int j = 0; j < 10; j++) winner[j] = p1[j];
            return 1;
        }
        if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
        {
            for (int j = 0; j < 10; j++) winner[j] = p2[j];
            return 1;
        }
    }
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
        {
            for (int j = 0; j < 10; j++) winner[j] = p1[j];
            return 1;
        }
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
        {
            for (int j = 0; j < 10; j++) winner[j] = p2[j];
            return 1;
        }
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
        {
            for (int j = 0; j < 10; j++) winner[j] = p1[j];
            return 1;
        }
    if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
        {
            for (int j = 0; j < 10; j++) winner[j] = p2[j];
            return 1;
        }
    if (isFilled()) return 1;
    return 0;
}

void main(void)
{
    printf("Welcome to TicTacToe! Press Enter to start ");
    scanf("*");
    resetBoard();
    displayBoard();
    while (1)
    {        
        move(p1);
        displayBoard();
        if (gameOver()) break;
        move(p2);
        displayBoard();
        if (gameOver()) break;
    }
    if (winner[0] == 0)
        printf("Match Over! It's a tie!!!\n");
    else
        printf("Good Game! %s is the winner.\n", winner);
    printf("\nDo you want to play another game?[Y/n] ");
    scanf("\n%c", &new);
    if (new == 'y' || new == 'Y')
        main();
}


//made by Abhinav Kumar, G1