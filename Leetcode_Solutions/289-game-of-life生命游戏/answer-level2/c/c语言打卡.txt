### 解题思路
此处撰写解题思路

### 代码

```c
void gameOfLife(int** board, int boardSize, int* boardColSize){
    int i, j, k, l, r, c;
    for(i = 0;i < boardSize;i ++)
        for(j = 0;j < boardColSize[i];j ++)
            if(board[i][j] % 10 == 1)
                for(k = -1;k <= 1;k ++){
                    r = i + k;
                    if(r >= 0 && r < boardSize)
                        for(l = -1;l <= 1;l ++){
                            c = j + l;
                            if(c >= 0 && c < boardColSize[r] && !(k == 0 && l == 0))
                                board[r][c] += 10;
                        }
                }
    for(i = 0;i < boardSize;i ++)
        for(j = 0;j < boardColSize[i];j ++)
            if(board[i][j] % 10 == 0)
                if(board[i][j] / 10 == 3)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            else
                if(board[i][j] / 10 < 2 || board[i][j] / 10 > 3)
                    board[i][j] = 0;
                else
                    board[i][j] = 1;
}
```