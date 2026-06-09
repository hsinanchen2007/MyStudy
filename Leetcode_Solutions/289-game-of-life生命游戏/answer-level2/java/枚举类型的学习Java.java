### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
  enum status {
		DIE, LIVE, RELIVE;
	}

	public void gameOfLife(int[][] board) {
		status s = status.DIE;
		int m = board.length;
		if (m == 0) {
			return;
		}

		int n = board[0].length;
		boolean[][] isAlive = new boolean[m][n];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				status l = getStatus(board, i, j);
				int k = board[i][j];
				if (l.equals(status.DIE) || (l.equals(status.LIVE) && k == 0)) {
					isAlive[i][j] = false;
				} else if (l.equals(status.LIVE) && k == 1
						|| l.equals(status.RELIVE)) {
					isAlive[i][j] = true;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (isAlive[i][j]) {
					board[i][j] = 1;
				} else {
					board[i][j] = 0;
				}
			}
		}

	}

	public status getStatus(int[][] board, int len, int wid) {
		int count=0;
		int m = board.length;
		int n = board[0].length;
		//up
		if(len-1>=0&&board[len-1][wid]==1){
			count++;
		}
		//down
		if(len+1<m&&board[len+1][wid]==1){
			count++;
		}
		//left
		if(wid+1<n&&board[len][wid+1]==1){
			count++;
		}
		//right
		if(wid-1>=0&&board[len][wid-1]==1){
			count++;
		}
		//up left
		if(len-1>=0&&wid-1>=0&&board[len-1][wid-1]==1){
			count++;
		}
		//up right
		if(len-1>=0&&wid+1<n&&board[len-1][wid+1]==1){
			count++;
		}
		//down left
		if(len+1<m&&wid-1>=0&&board[len+1][wid-1]==1){
			count++;
		}
		//down right
		if(len+1<m&&wid+1<n&&board[len+1][wid+1]==1){
			count++;
		}
		if(count<2||count>3){
			return status.DIE;
		}else if(count==3){
			return status.RELIVE;
		}else {
			return status.LIVE;
		}

	}
}
```