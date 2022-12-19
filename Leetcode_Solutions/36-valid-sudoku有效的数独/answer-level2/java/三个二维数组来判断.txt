### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[][] row=new boolean[9][9];
		  boolean[][] col=new boolean[9][9];
		  boolean[][] div=new boolean[9][9];
		  for(int i=0;i<9;i++) {
			  for(int j=0;j<9;j++) {
				  if(board[i][j]=='.') {
					  continue;
				  }
				  else {
					 int k = board[i][j]-49;
					 if(row[i][k]||col[k][j]||div[(i/3)*3+k/3][(j/3)*3+k%3])
						 return false;
					 else {
						 row[i][k]=true;
						 col[k][j]=true;
						 div[(i/3)*3+k/3][(j/3)*3+k%3]=true;
					 }
				  }
			  }
		  }
		  return true;
    }
}
```