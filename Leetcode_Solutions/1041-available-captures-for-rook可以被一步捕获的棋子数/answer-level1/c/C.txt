### 解题思路
最简单的BFS

### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int i, j;
    int sum = 0;
    int rockx = 0, rocky = 0;
    int currx, curry;
    int dir[4][2] = { {0, 1},{ 0, -1 },{ 1, 0 },{ -1, 0 } };

    // 先找到rock的坐标位置
    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == 'R') {
                rockx = i;
                rocky = j;
                break;
            }
        }
    }

    // 从该坐标位置开始4个方向搜索一遍，遇到边界或遇到pawn停止
    for (i = 0; i < 4; i++) {
        currx = rockx + dir[i][0];
        curry = rocky + dir[i][1];
        while (currx >= 0 && currx < boardSize && curry >= 0 && curry < boardColSize[0]) {
            if (board[currx][curry] == 'p') {
                sum++;
                break;
            } 
            if (board[currx][curry] == 'B') {
                break;
            }
            currx = currx + dir[i][0];
            curry = curry + dir[i][1];
        }
    }
    return sum;
}
```