### 解题思路
此处撰写解题思路

### 代码

```java
public class TicTacToe {
	private int[][] scope;
	public TicTacToe(int n) {
		scope = new int[n][n];
	}

	public int move(int row, int col, int player) {
		scope[row][col] = player;
		// 横
		boolean win = true;
		for (int item : scope[row]) {
			if (item != player) {
				win = false;
				break;
			}
		}
		if (win) {
			return player;
		}
		// 竖
		win = true;
		for (int i = 0; i < scope.length; i++) {
			if (scope[i][col] != player) {
				win = false;
				break;
			}
		}
		if (win) {
			return player;
		}
		// 左对角
		win = true;
		for (int i = 0; i < scope.length; i++) {
			if (scope[i][i] != player) {
				win = false;
				break;
			}
		}
		if (win) {
			return player;
		}
		// 有对角
		win = true;
		for (int i = 0; i < scope.length; i++) {
			if (scope[i][scope.length - 1 - i] != player) {
				win = false;
				break;
			}
		}
		if (win) {
			return player;
		} else {
			return 0;
		}
	}
}
```