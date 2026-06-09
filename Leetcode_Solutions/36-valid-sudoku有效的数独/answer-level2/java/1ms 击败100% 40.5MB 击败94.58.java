### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
       for(int i=0;i<board.length;i++) {
			for(int j=0;j<board[i].length;j++) {
				if(board[i][j]!='.') {
					if(!check(board, i, j, board[i][j])) return false;
				}
			}
		}
		return true;
    }
   private boolean check(char[][] board,int x,int y,char a) {
		if(a=='.') return true;
		int x1=(x/3)*3;
		int y1=(y/3)*3;
		for(int i=x1;i<x1+3;i++) {
			for(int j=y1;j<y1+3;j++) {
				if(board[i][j]==a&&i!=x&&j!=y) return false;
			}
		}
		for(int i=0;i<=8;i++) {
			if((board[x][i]==a&&y!=i)||(board[i][y]==a&&x!=i)) return false;
		}
		return true;
	}
}
```