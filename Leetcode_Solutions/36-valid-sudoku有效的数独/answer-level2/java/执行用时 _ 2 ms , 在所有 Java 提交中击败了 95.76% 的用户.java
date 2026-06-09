
执行用时 :2 ms, 在所有 Java 提交中击败了95.76%的用户内存消耗 :41.1 MB, 在所有 Java 提交中击败了93.83%的用户
### 解题思路
用空间换时间。思路简单。
### 代码

```java
class Solution {
private boolean row[][] = new boolean[9][9];//这个是行
private boolean con[][] = new boolean[9][9];//这个是列
private boolean cross[][][] = new boolean[3][3][9];//这个是方框

	public boolean isValidSudoku(char[][] board) {
		for(int i = 0;i<9;i++) {
			for(int j = 0;j<9;j++) {
				if(board[i][j] == '.')
					continue;
				if(row[i][board[i][j]-49]) {
					return false;
				}else
					row[i][board[i][j]-49]=true;
				if(con[j][board[i][j]-49]) {
					return false;
				}else
					con[j][board[i][j]-49]=true;
				if(cross[i/3][j/3][board[i][j]-49]) {
					return false;
				}else
					cross[i/3][j/3][board[i][j]-49]=true;
			}
		}
		return true;
    }
}
```