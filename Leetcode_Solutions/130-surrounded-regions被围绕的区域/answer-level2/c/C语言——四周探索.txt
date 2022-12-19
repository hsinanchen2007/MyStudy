### 解题思路
此处撰写解题思路
此题与岛屿归并属于同一思路；
（1）定义一个二维数组探索该二维数组中首行、首列、尾行、尾列每个湖泊所能探索的最大深度，并标志位1
（2）遍历数组，所有非1的地方都是可达到的陆地，置为‘X’即可。

### 代码

```c
void myFindCircleNum(char **M, int **arr, int ROW, int COL, int row, int col)
{
    if (row >= 0 && row < ROW && col >= 0 && col < COL && (M[row][col] == 'O') && (arr[row][col] == 0)) {        
            arr[row][col] = 1;
            myFindCircleNum(M, arr, ROW, COL, row - 1, col);
            myFindCircleNum(M, arr, ROW, COL, row + 1, col);
            myFindCircleNum(M, arr, ROW, COL, row, col - 1);
            myFindCircleNum(M, arr, ROW, COL, row, col + 1);
    }
}

void solve(char** board, int boardSize, int* boardColSize){
    int **arr = NULL;
    int row, col, i, j;

    if (board == NULL || boardSize <= 1 || *boardColSize <= 1) {
        return;
    }

    row = boardSize;
    col = *boardColSize;
     
    arr = (int **)malloc(sizeof(int *) * row);
    for (i = 0; i < row; i++) {
        arr[i] = (int *)malloc(sizeof(int) * col);
        memset(arr[i], 0, sizeof(int) * col);
    }

    /* 首行 */
    for (i = 0; i < col; i++) {
        if (arr[0][i] == 0 && board[0][i] == 'O') {
            myFindCircleNum(board, arr, row, col, 0, i);
        }
    }

    /* 首列 */
    for (i = 0; i < row; i++) {
        if (arr[i][0] == 0 && board[i][0] == 'O') {
            myFindCircleNum(board, arr, row, col, i, 0);
        }
    }

    /* 尾列 */
    for (i = 0; i < row; i++) {
        if (arr[i][col - 1] == 0 && board[i][col - 1] == 'O') {
            myFindCircleNum(board, arr, row, col, i, col - 1);
        }
    }

    /* 尾行 */
    for (i = 0; i < col; i++) {
        if (arr[row - 1][i] == 0 && board[row - 1][i] == 'O') {
            myFindCircleNum(board, arr, row, col, row - 1, i);
        }
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (arr[i][j] == 1) {
                board[i][j] = 'O';
            } else {
                board[i][j] = 'X';
            }
        }
    }

    for (i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);
}

```