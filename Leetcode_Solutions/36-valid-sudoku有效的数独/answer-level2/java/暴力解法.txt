### 解题思路
简单粗暴，直接对每一行，每一列，每一宫检测
这里注意的就是对于第k个宫格，如何由k得出每一格的坐标
### 代码

```java
class Solution {
    	public boolean isValidSudoku(char[][] board) {
		return checkRows(board) && checkLines(board) && checkSquares(board);

	}
	
	public boolean checkRows(char[][] board) {
		List<Character> list = new ArrayList<>();
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if ((board[i][j]) != '.')
					if (!list.contains(board[i][j]))
						list.add(board[i][j]);
					else
						return false;
			}
			list.clear();
		}
		return true;
	}

	public boolean checkLines(char[][] board) {
		List<Character> list = new ArrayList<>();
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if ((board[j][i]) != '.')
					if (!list.contains(board[j][i]))
						list.add(board[j][i]);
					else
						return false;
			}
			list.clear();
		}
		return true;
	}

	public boolean checkSquares(char[][] board) {
		List<Character> list = new ArrayList<>();
		for (int k = 0; k < 9; k++) {
			for (int i = (k / 3) * 3; i < (k / 3) * 3 + 3; i++) {
				for (int j = (k % 3) * 3; j < (k % 3) * 3 + 3; j++) {
					if ((board[i][j]) != '.')
						if (!list.contains(board[i][j]))
							list.add(board[i][j]);
						else
							return false;
				}
			}
			list.clear();
		}
		return true;
	}
}
```