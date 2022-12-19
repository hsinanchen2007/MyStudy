### 解题思路
    使用原地算法解决思路：将由死细胞（dead）变为活细胞（live）的细胞标记为2，将由dead变为live的细胞标记为3；在本次查找中，2仍然表示dead，3仍然表示live；查找完成之后，将标记为3的细胞当做live，改为1，将标记为2的细胞当做dead，改为0.

### 代码

```c
void gameOfLife(int** board, int boardSize, int* boardColSize){
    int cnt;
    for(int i = 0; i < boardSize; ++i){
        for(int j = 0; j < boardColSize[i]; ++j){
            cnt = 0;
            if(i > 0){
                if(j > 0){
                    if(board[i-1][j-1] == 1 || board[i-1][j-1] == 3){
                        cnt++;
                    }
                }
                if(board[i-1][j] == 1 || board[i-1][j] == 3){
                    cnt++;
                }
                if(j < boardColSize[i] - 1){
                    if(board[i-1][j+1] == 1 || board[i-1][j+1] == 3){
                        cnt++;
                    }
                }
            }
            if(j > 0){
                if(board[i][j-1] == 1 || board[i][j-1] == 3){
                    cnt++;
                }
            }
            if(j < boardColSize[i] - 1){
                if(board[i][j+1] == 1 || board[i][j+1] == 3){
                    cnt++;
                }
            }
            if(i < boardSize - 1){
                if(j > 0){
                    if(board[i+1][j-1] == 1 || board[i+1][j-1] == 3){
                        cnt++;
                    }
                }
                if(board[i+1][j] == 1 || board[i+1][j] == 3){
                    cnt++;
                }
                if(j < boardColSize[i] - 1){
                    if(board[i+1][j+1] == 1 || board[i+1][j+1] == 3){
                        cnt++;
                    }
                }
            }
            if(cnt < 2){
                if(board[i][j] == 1){
                    board[i][j] = 3;
                }
            }
            if(cnt == 3){
                if(board[i][j] == 0){
                    board[i][j] = 2;
                }
            }
            if(cnt > 3){
                if(board[i][j] == 1){
                    board[i][j] = 3;
                }
            }
        }
    }
    for(int i = 0; i < boardSize; ++i){
        for(int j = 0; j < boardColSize[i]; ++j){
            if(board[i][j] == 2){
                board[i][j] = 1;
            }
            if(board[i][j] == 3){
                board[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < boardSize; ++i){
        for(int j = 0; j < boardColSize[i]; ++j){
            if(j == 0){
                printf("%d", board[i][j]);
            }
            else{
                printf(" %d", board[i][j]);
            }
        }
        printf("\n");
    }
    return;
}
```