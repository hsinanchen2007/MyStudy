### 解题思路
拷贝一个`board_tmp`作为当前细胞状态，board存放下一次结果
遍历`board_tmp`中每一个细胞，根据条件更新board

### 代码

```c

int getAlive(int **board, int boardSize, int boardColSize, int row, int col) {
	int sum = 0;
	if (row > 0) {
		sum += board[row - 1][col];  // 上
	}
	if (row < boardSize - 1) {
		sum += board[row + 1][col];   // 下
	}

	if (col > 0) {
		sum += board[row][col - 1];   //左
		if (row > 0) {
			sum += board[row - 1][col - 1];   // 左上
		}
		if (row < boardSize - 1) {
			sum += board[row + 1][col - 1];   // 左下
		}
	}
	if (col < boardColSize - 1) {
		sum += board[row][col + 1];   // 右
		if (row > 0) {
			sum += board[row - 1][col + 1];   // 右上
		}
		if (row < boardSize - 1) {
			sum += board[row + 1][col + 1];   // 右下
		}
	}
	return sum;
}

void gameOfLife(int** board, int boardSize, int* boardColSize) {
	// 特判
	if (!board || boardSize == 0 || 0 == *boardColSize)
		return;
	// 创建
	int **board_tmp = (int **) malloc(boardSize * sizeof(int *));
	for (int i = 0; i < boardSize; i++) {
		board_tmp[i] = (int *) malloc(sizeof(int) * (*boardColSize));
	}
	// 拷贝
	for (int row = 0; row < boardSize; row++) {
		for (int col = 0; col < *boardColSize; col++) {
			board_tmp[row][col] = board[row][col];
		}
	}
	int count;
	for (int row = 0; row < boardSize; row++) {
		for (int col = 0; col < *boardColSize; col++) {
			count = getAlive(board_tmp, boardSize, *boardColSize, row, col);
			if (count < 2)
				board[row][col] = 0;
			else if (count == 3) {
				if (board[row][col] == 0)
					board[row][col] = 1;
			} else if (count > 3) {
				board[row][col] = 0;
			}
		}
	}
}

```