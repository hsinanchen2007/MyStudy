### 解题思路
执行用时 :100.00%
内存消耗 :100.00%
技巧点有二：1、用while一直沿直线走下去，2、用两个数组来判断方向

### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    // 定义上下左右四个方向
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        *boardColSize = boardSize;
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                // 找到白车所在的位置
                if (board[i][j] == 'R') {
                    // 分别判断白车的上、下、左、右四个方向
                    int res = 0;
                    for (int k = 0; k < 4; k++) {
                        int x = i, y = j;
                        while (true) {
                            x += dx[k];
                            y += dy[k];
                            if (x < 0 || x >= boardSize || y < 0 || y >= boardSize || board[x][y] == 'B') {
                                break;
                            }
                            if (board[x][y] == 'p') {
                                res++;
                                break;
                            }
                        }
                    }

                    return res;
                }
            }
        }

        return 0;
}
```