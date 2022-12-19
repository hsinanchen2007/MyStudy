### 解题思路
此处撰写解题思路

### 代码

```c
void gameOfLife(int** board, int boardSize, int* boardColSize){
    if (board == NULL || boardSize == 0 || boardColSize == NULL || *boardColSize == 0) {
        return;
    }

    int **temp = (int**)malloc(sizeof(int*) * boardSize);
    int i, j, k;
    int live;
    int next[8][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int next_x, next_y;
    
    for (i = 0; i < boardSize; i++) {
        temp[i] = (int*)malloc(sizeof(int) * boardColSize[i]);
        for (j = 0; j < boardColSize[i]; j++) {
            live = 0;
            for (k = 0; k < 8; k++) {
                next_x = i + next[k][0];
                next_y = j + next[k][1];
                if (next_x >= 0 && next_x < boardSize && next_y >= 0 && next_y < boardColSize[i]) {
                    if (board[next_x][next_y] == 1) {
                        live++;
                    }
                }
            }
            if (board[i][j] == 1) {
                if (live > 3 || live < 2) {
                    temp[i][j] = 0;
                } else {
                    temp[i][j] = 1;
                }
            } else {
                if (live == 3) {
                    temp[i][j] = 1;
                } else {
                    temp[i][j] = 0;
                }
            }
        }
    }

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[i]; j++) {
            board[i][j] = temp[i][j];
        }
    }

    for (i = 0; i < boardSize; i++) {
        free(temp[i]);
    }
    free(temp);
}
```