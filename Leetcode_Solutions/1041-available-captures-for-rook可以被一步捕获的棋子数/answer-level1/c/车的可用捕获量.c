### 解题思路
先找出R的位置，然后行列扫描能吃到的p
### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize) {
	int res = 0;  
	int flag = 0;
	int i, j;
	for (i = 0; i < boardSize; i++) {
		for (j = 0; j < boardColSize[i]; j++) {
			if (board[i][j] == 'R') {
				flag = 1;break;
			}
		}
		if (flag) break;
	}
	for (int k = i-1; k >= 0; k--) {
		if (board[k][j] == 'B') break;
		if (board[k][j] == 'p') {
			res++;break;
		}
	}
	for (int k = i + 1; k < boardSize; k++) {
		if (board[k][j] == 'B') break;
		if (board[k][j] == 'p') {
			res++;break;
		}
	}
	for (int k = j-1; k >=0; k--) {
		if (board[i][k] == 'B') break;
		if (board[i][k] == 'p') {
			res++;break;
		}
	}
	for (int k = j + 1; k < boardSize; k++) {
		if (board[i][k] == 'B') break;
		if (board[i][k] == 'p') {
			res++;break;
		}
	}
	return res;
}
```