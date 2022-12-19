```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int numRookCaptures(char** board, int boardSize, int* boardColSize)
{
    int x, y;
    int r = 0;
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < *boardColSize; j++)
        {
            if(board[i][j] == 'R')
            {
                x = i, y = j;
                break;
            }
        }
    }

    // 向上搜索
    for(int i = x - 1; i >= 0; i--)
    {
        if(board[i][y] == 'B')
            break;
        else if(board[i][y] == 'p')
        {
            r++;
            break;
        }
    }

    // 向下搜索
    for(int i = x + 1; i < *boardColSize; i++)
    {
        if(board[i][y] == 'B')
            break;
        else if(board[i][y] == 'p')
        {
            r++;
            break;
        }
    }

    // 向右搜索
    for(int i = y + 1; i < boardSize; i++)
    {
        if(board[x][i] == 'B')
            break;
        else if(board[x][i] == 'p')
        {
            r++;
            break;
        }
    }
    // 向左搜索
    for(int i = y - 1; i >= 0; i--)
    {
        if(board[x][i] == 'B')
            break;
        else if(board[x][i] == 'p')
        {
            r++;
            break;
        }
    }
    return r;
}

int main(void)
{
    // char chess[8][8] = {{".", ".", ".", ".", ".", ".", ".", "."}, {".", ".", ".", "p", ".", ".", ".", "."}, {".", ".", ".", "R", ".", ".", ".",
    // "p"},
    //{".", ".", ".", ".", ".", ".", ".", "."}, {".", ".", ".", ".", ".", ".", ".", "."}, {".", ".", ".", "p", ".", ".", ".", "."},
    //{".", ".", ".", ".", ".", ".", ".", "."}, {".", ".", ".", ".", ".", ".", ".", "."}};

    // char* chess[8] = {
    //"........", "...p....", "...R...p", "........", "........", "...p....", "........", "........",
    //};

    char* chess[8] = {"........", "..BBBBB.", ".pBpppBp", ".pBpRpBp", ".pBpppBp", "..BBBBB.", "...ppp..", "........"};
    int   col      = 8;
    printf("%d\n", numRookCaptures(chess, 8, &col));

    return 0;
}
```