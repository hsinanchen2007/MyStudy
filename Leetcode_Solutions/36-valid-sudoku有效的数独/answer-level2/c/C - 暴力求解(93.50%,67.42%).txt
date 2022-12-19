循环多次，先横，后竖，再九宫。
手动存储九宫格，（先九宫格因该可以提升效率）
```
bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    char temp[9];
    int i,j,k,m,n;
    for (i = 0; i < 9; ++i){
        for (j = 0; j < 9; ++j){
            if(board[i][j] == '.')
                continue;
            for (k = j+1; k < 9; ++k){
                if(board[i][k] == '.')
                    continue;
                if(board[i][k] == board[i][j]){
                    return false;
                }
            }
        }
    }
    for (i = 0; i < 9; ++i){
        for (j = 0; j < 9; ++j){
            if(board[j][i] == '.')
                continue;
            for (k = j+1; k < 9; ++k){
                if(board[k][i] == '.')
                    continue;
                if(board[k][i] == board[j][i]){
                    return false;
                }
            }
        }
    }
    for (i = 0; i < 9; ++i)
        for (j = 0; j < 9; ++j)
            if (i%3==0&&j%3==0)
            {
                temp[0] = board[i][j];
                temp[1] = board[i][j+1];
                temp[2] = board[i][j+2];
                temp[3] = board[i+1][j];
                temp[4] = board[i+1][j+1];
                temp[5] = board[i+1][j+2];
                temp[6] = board[i+2][j];
                temp[7] = board[i+2][j+1];
                temp[8] = board[i+2][j+2]; 
                for (m = 0; m < 9; ++m)
                {
                    if (temp[m] == '.')
                        continue;
                    for (n = m+1; n < 9; ++n)
                    {
                        if (temp[n] == '.')
                            continue;
                        if (temp[m] == temp[n])
                            return false;
                    }
                }
            }
    return true;
}
```
