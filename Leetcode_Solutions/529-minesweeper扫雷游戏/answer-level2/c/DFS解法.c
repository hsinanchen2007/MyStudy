### 解题思路
0、根据题意，当前点内容为E，才进行计算，否自直接返回；
1、更新当前点，根据周围雷的数量;
2、如果当前点是为空，即B，则往8个方向dfs。

### 代码
```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define LEN 8
char updatePoint(char **buf, int boardSize, int *retc, int i, int j)
{
    char tmp[LEN];
    int num = 0;
    int row[LEN] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int col[LEN] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    for (int n = 0; n < LEN; n++) {
        if (i + row[n] >= 0 && i + row[n] < boardSize && j + col[n] >= 0 && j + col[n] < retc[i]) { 
            if (buf[i + row[n]][j + col[n]] == 'M') {
                num++;
            }
        }
    }

    if (num > 0) {
        buf[i][j] = '0' + num;
    } else {
        buf[i][j] = 'B';
    }
    
    return buf[i][j];
}

void dfs(char **buf, int boardSize, int *retc, int i, int j)
{
    if (i < 0 || j < 0 || i >= boardSize || j >= retc[i]) {
        return;
    }

    if (buf[i][j] != 'E') {
        return;
    }

    int row[LEN] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int col[LEN] = {0, 1, 1, 1, 0, -1, -1, -1};

    if (updatePoint(buf, boardSize, retc, i, j) == 'B') {
        for (int m = 0; m < LEN; m++) {
            dfs(buf, boardSize, retc, i + row[m], j + col[m]);
        }
    }
}

char **updateBoard(char **board, int boardSize, int *boardColSize, int *click, int clickSize, int *returnSize,
                   int **returnColumnSizes)
{
    char **buf = (char **)malloc(sizeof(char *) * boardSize);
    for (int i = 0; i < boardSize; i++) {
        buf[i] = (char *)malloc(sizeof(char) * boardColSize[i]);
    }

    for(int m = 0; m < boardSize; m++) {
        for(int n = 0; n < boardColSize[m]; n++) {
            buf[m][n] = board[m][n];
        }
    }

    int *retc = (int *)malloc(sizeof(int) * boardSize);
    memcpy(retc, boardColSize, sizeof(int) * boardSize);

    if (buf[click[0]][click[1]] == 'M') {
        buf[click[0]][click[1]] = 'X';
    }

    if (buf[click[0]][click[1]] == 'E') {
        dfs(buf, boardSize, retc, click[0], click[1]);
    }

    *returnSize = boardSize;
    *returnColumnSizes = retc;
    return buf;
}