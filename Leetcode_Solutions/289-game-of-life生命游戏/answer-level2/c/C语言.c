### 解题思路
没什么特别解法，用个全局数组模拟八个方向，统计周围细胞存活数量后根据不同条件决定细胞是否存活

### 代码

```c
// 全局变量用来计算八个方向的方位
int g_site[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
int getLive(int x, int y, int** board, int boardSize, int* boardColSize) {
    int i, j;
    int ans = 0;
    for (i = 0; i < 8; i++) {
        if (x + g_site[i][0] < 0 || x + g_site[i][0] >= boardSize || 
            y + g_site[i][1] < 0 || y + g_site[i][1] >= boardColSize[0]) {
            continue;
        }
        ans += board[x + g_site[i][0]][y + g_site[i][1]];
    }
    return ans;
}
void gameOfLife(int** board, int boardSize, int* boardColSize){
    int **follow = (int **)malloc(sizeof(int *) * boardSize);
    int i, j;
    int temp;
    for (i = 0; i < boardSize; i++) {
        follow[i] = (int *)malloc(sizeof(int) * boardColSize[0]);
        memset(follow[i], 0, sizeof(int) * boardColSize[0]);
    }
    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[0]; j++) {
            temp = getLive(i, j, board, boardSize, boardColSize);
            if (temp < 2 || temp > 3) {
                follow[i][j] = 0;
                continue;
            }
            if (temp == 3) {
                follow[i][j] = 1;
                continue;
            }
            follow[i][j] = board[i][j];
        }
    }
    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[0]; j++) {
            board[i][j] = follow[i][j];
        }
    }
    return;
}
```