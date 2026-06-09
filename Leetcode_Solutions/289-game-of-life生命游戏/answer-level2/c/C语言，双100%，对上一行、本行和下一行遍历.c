解题思路 先开个数组用来记录二维数组每个位置周围的活细胞数目，然后遍历二维数组，只对该位置的上一行、本行和下一行遍历（最多遍历3个数），记录活细胞数目，二维数组遍历完后，在遍历一次根据活细胞数目判断该细胞是死是活。
```
void gameOfLife(int** board, int boardSize, int* boardColSize){
    int i, j, count = 0, x, y;
    int *s = (int *)malloc(sizeof(int) * (boardSize * boardColSize[0] + 1));
    memset(s, 0, sizeof(int) * (boardSize * boardColSize[0] + 1));
    y = 0;
    for(i = 0;i < boardSize;i++)
    {
        for(j = 0;j < boardColSize[0];j++)
        {
            count = 0;
            for(x = j - 1;x <= j + 1;x++)
            {
                if(i - 1 < 0)
                    break;
                if(x < 0)
                    continue;
                if(x >= boardColSize[0])
                    break;
                if(board[i - 1][x] == 1)
                {
                   count++;
                }
            }
            for(x = j - 1;x <= j + 1;x++)
            {
                if(x < 0)
                    continue;
                if(x >= boardColSize[0])
                    break;
                if(x == j)
                    continue;
                if(board[i][x] == 1)
                {
                    count++;
                }
            }
             for(x = j - 1;x <= j + 1;x++)
            {
                if(i + 1 >= boardSize)
                    break;
                if(x < 0)
                    continue;
                if(x >= boardColSize[0])
                    break;
                if(board[i + 1][x] == 1)
                {
                    count++;
                }
            }
            s[y++] = count;
        }
    }
    y = -1;
    for(i = 0;i < boardSize;i++)
    {
        for(j = 0;j < boardColSize[0];j++)
        {
            y++;
            if(board[i][j] == 0)
            {
                if(s[y] == 3)
                    board[i][j] = 1;
            }
            else if(board[i][j] == 1)
            {
                if(s[y] != 2 && s[y] != 3)
                    board[i][j] = 0;
            }
        }
    }
}
```

