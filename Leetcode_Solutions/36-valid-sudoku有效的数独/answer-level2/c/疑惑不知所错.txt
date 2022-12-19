无论是用3次遍历还是一次遍历，C语言写的代码始终停留在第345个用例上。
思考许久确实不知何错，烦请大家帮忙看看。
```
bool isValidSudoku(char** board, int boardSize, int* boardColSize){ 
    
	int rows[9][10], cols[9][10], boxs[9][10];
	
	int i, j;
	for (i = 0; i < 9; i++) {
		memset(rows[i], 0, sizeof(int));
		memset(cols[i], 0, sizeof(int));
		memset(boxs[i], 0, sizeof(int));
	}
	
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (board[i][j] != '.') {
				int num = board[i][j] - '0';
				
				rows[i][num]++;
				cols[j][num]++;
				boxs[(i/3)*3 + j/3][num]++;
				
				if (rows[i][num] > 1 || cols[j][num] > 1 || boxs[(i/3)*3 + j/3][num] > 1)
					return false;
			}
		}
	}
	return true;
}
```
