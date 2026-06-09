### 解题思路
此处撰写解题思路

### 代码

```c
int direct[8][2] = {{-1,-1},{-1,0},{-1 , 1}, {0,-1}, {0,1}, {1,-1},{1,0},{1,1}};
int getLifeCellNum(int** board, int boardSize, int* boardColSize, int m, int n)
{
    int i;
    int j;
    int boardid;
    int col;
    int result = 0;
    for (i = 0; i < 8; i++) {
        boardid = m + direct[i][0];
        col = n + direct[i][1];
        if ((boardid >= 0) && (boardid < boardSize) && (col >= 0) && (col < boardColSize[m])) {
            if (board[boardid][col] == 1) {
                result++;
            }
        }
    }
    return result;
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    int i;
    int j;
    int **tmp;
    if ((board == NULL) || (boardSize == 0) || (boardColSize == NULL)) {
        return;
    }
    tmp = (int **)malloc(sizeof(int *) * boardSize);
    for (i = 0; i < boardSize; i++) {
        tmp[i] = (int *)malloc(sizeof(int) * boardColSize[i]);
    }

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[i]; j++) {
            tmp[i][j] = getLifeCellNum(board, boardSize, boardColSize, i, j);
        }
    }
    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[i]; j++) {
            if (board[i][j]) {
                if((tmp[i][j] != 2) && (tmp[i][j] != 3)) {
                    board[i][j] = 0;
                }
            } else {
                if (tmp[i][j] == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
    for (i = 0; i < boardSize; i++) {
        free(tmp[i]);
    }
    free(tmp);

    return;
}