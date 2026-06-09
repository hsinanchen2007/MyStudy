### 解题思路
拷贝一份原始状态，根据规则更新状态；
或者引入复合状态，能知道之前和之后的状态（-1：从活到死；2：从死到活）
溜了溜了。

### 代码1

```c
int calLiveAround(int** board, int x, int y, int row, int col) {
    int i;
    int j;
    int LiveCnt = 0;

    for (i=x-1; i<=x+1; i++) {
        for (j=y-1; j<=y+1; j++) {
            if (i<0 || j<0 || i>=row || j>=col) continue;
            if (i==x && j==y) continue;
            if (board[i][j]) LiveCnt++;
        }
    }
    return LiveCnt;
}


void gameOfLife(int** board, int boardSize, int* boardColSize){
    int row = boardSize;
    int col = *boardColSize;
    int i;
    int j;
    int liveCnt;

    if (boardSize == 0 || board == NULL) {
        return;
    }

    int **mir = (int**)malloc(row*sizeof(int*));
    if (!mir) return;

    for (i=0; i<row; i++) {
        mir[i] = (int*)malloc(col*sizeof(int));
        (void)memcpy(mir[i], board[i], col*sizeof(int));
    }

    for (i=0; i<row; i++) {
        for (j=0; j<col; j++) {
            liveCnt =calLiveAround(mir, i, j, row, col);
            if (liveCnt < 2 && board[i][j]) board[i][j] = 0;
            else if ((liveCnt == 2 || liveCnt == 3) && board[i][j]) board[i][j] = 1;
            else if (liveCnt > 3 && board[i][j]) board[i][j] = 0;
            else if (liveCnt == 3 && !board[i][j]) board[i][j] = 1;
        }
    }

    for (i=0; i<row; i++) {
        (void)free(mir[i]);
    }
    free(mir);

    return;
}
```
### 代码2

```c
int calLive(int** board, int boardSize, int* boardColSize, int i, int j) {
    int neighbor[] = {-1, 0, 1};
    int liveCnt = 0;

    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            int x = i + neighbor[k];
            int y = j + neighbor[l];
            if (x < 0 || x >= boardSize || y < 0 || y >= boardColSize[0]) continue;
            if (x == i && y == j) continue;

            if (board[x][y] == 1 || board[x][y] == -1) liveCnt++;
        }
    }
    return liveCnt;
}

void gameOfLife(int** board, int boardSize, int* boardColSize){


    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            int liveCnt = calLive(board, boardSize, boardColSize, i, j);
            if ((liveCnt < 2 || liveCnt > 3) && board[i][j]) board[i][j] = -1;
            else if (liveCnt == 3 && board[i][j] == 0) board[i][j] = 2; 
        }
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            if (board[i][j] == 2) board[i][j] = 1;
            else if (board[i][j] == -1) board[i][j] = 0;
        }
    }
    return;
}
```