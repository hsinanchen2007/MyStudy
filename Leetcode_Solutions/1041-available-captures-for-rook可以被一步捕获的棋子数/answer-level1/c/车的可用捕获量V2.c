### 解题思路
使用方向数组简化四个for的语句写法

### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize) {
	int res = 0;  
	int flag = 0;
	int i, j;
    int dx[4] = {0, 1, 0, -1}; //方向数组
    int dy[4] = {1, 0, -1, 0}; //方向数组
	for (i = 0; i < boardSize; i++) {
		for (j = 0; j < boardColSize[i]; j++) {
			if (board[i][j] == 'R') {
				flag = 1;break;
			}
		}
		if (flag) break;
	}
    for (int k = 0; k < 4; k++) {
        for (int step = 0;; ++step) {
            int tx = i + step * dx[k];
            int ty = j + step * dy[k];
            if (tx < 0 || tx >= 8 || ty < 0 || ty >= 8 || board[tx][ty] == 'B') break;
            if (board[tx][ty] == 'p') {
                res++;
                break;
            }
        }
    }
	return res;
}
```