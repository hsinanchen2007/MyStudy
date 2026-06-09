### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public boolean exist(char[][] board, String word) {
		boolean[][] vist=new boolean[board.length][board[0].length];
		for(int i=0;i<board.length;i++) {
			for(int j=0;j<board[i].length;j++) {
				if(dfs(board,word,i,j,vist,0)) {
					return true;
				}
				//return false;
			}
		}
		return false;
    }

	private boolean dfs(char[][] board, String word, int i, int j, boolean[][] vist, int k) {
		
		
		if(i<0 || i>=board.length || j<0 ||j>=board[0].length ||vist[i][j]) {
			return false;
		}
		if(word.charAt(k)!=board[i][j]) {
			return false;
		}
		if(word.length()-1==k) {
			return true;
		}
		
		vist[i][j]=true;
		
		boolean flag =dfs(board, word, i+1, j, vist, k+1)||
					dfs(board, word, i-1, j, vist, k+1)||
					dfs(board, word, i, j-1, vist, k+1)||
					dfs(board, word, i, j+1, vist, k+1);
		
		vist[i][j]=false;
		
		return flag;
	}
}
```