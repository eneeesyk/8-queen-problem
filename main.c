#include <stdio.h>

int isSafe(char board[8][8], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i] == 'Q')
            return -1;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return -1;

    for (i = row, j = col; j >= 0 && i < 8; i++, j--)
        if (board[i][j] == 'Q')
            return -1;

    return 0;
}

int solve(char board[8][8], int col)
{
    if(col >= 8)
        return 0;

    for (int i = 0; i < 8; i++) {

        if (isSafe(board, i, col) == 0){
            board[i][col] = 'Q';

            if (solve(board, col+1) == 0)
                return 0;
            board[i][col] = '-';
        }
    }
    return -1;
}


int main() {

    char board[8][8] = { { '-', '-', '-', '-','-', '-', '-', '-' },
                        { '-', '-', '-', '-','-', '-', '-', '-' },
                        { '-', '-', '-', '-','-', '-', '-', '-' },
                        { '-', '-', '-', '-','-', '-', '-', '-' },
                        { '-', '-', '-', '-','-', '-', '-', '-' },
                        { '-', '-', '-', '-','-', '-', '-', '-' },
                        { '-', '-', '-', '-','-', '-', '-', '-' },
                        { '-', '-', '-', '-','-', '-', '-', '-' }};

    solve(board, 0);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            printf(" %c ", board[i][j]);
        printf("\n");
    }

    return 0;
}
