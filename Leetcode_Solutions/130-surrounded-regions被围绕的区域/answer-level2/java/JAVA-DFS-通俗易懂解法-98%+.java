![1575172866031.jpg](https://pic.leetcode-cn.com/4c4984d2bd2ec63bbd7a1c4ce3b470fc43056bada093efb7e81e5a289b8df8f8-1575172866031.jpg)

```
class Solution {
 	//从边界上到O出发,如果非边界O能连通边界O那么都是不可以被改为X的
    public void solve(char[][] board) {
        if (null == board || board.length <=1
        		|| board[0].length <=1) {
        	//只有一行，或者只有一列的时候，'O'都不能被标记为'X'
			return;
		}
        int rows             = board.length -1;
        int columns          = board[0].length -1;
        //把边界O改为D
        //修改第一列和最后一列
        for (int i = 0; i <= rows; i++) {
			if (board[i][0] == 'O') {
				board[i][0] = 'D';
			}
			if (board[i][columns] == 'O') {
				board[i][columns] = 'D';
			}
		}
        //修改第一行和最后一行
        for (int i = 0; i <= columns; i++) {
			if (board[0][i] == 'O') {
				board[0][i] = 'D';
			}
			if (board[rows][i] == 'O') {
				board[rows][i] = 'D';
			}
		}
        //开始从边界遍历吧
        for (int i = 0; i <= rows; i++) {
			for (int j = 0; j <= columns; j++) {
				if (board[i][j] =='D') {
					//四个方向递归
					//上
					dfs(board, i-1, j, rows, columns);
					//下
					dfs(board, i+1, j, rows, columns);
					//左
					dfs(board, i, j-1, rows, columns);
					//右
					dfs(board, i, j+1, rows, columns);
					
				}
			}
		}
        //结束之后，把O改为X
        for (int i = 0; i <= rows; i++) {
			for (int j = 0; j <= columns; j++) {
				if (board[i][j] =='O') {
					board[i][j] = 'X';
				}
			}
		}
        for (int i = 0; i <= rows; i++) {
			for (int j = 0; j <= columns; j++) {
				if (board[i][j] =='D' || board[i][j] =='P') {
					board[i][j] = 'O';
				}
			}
		}
        
    }
	public void  dfs(char[][] board,int i,int j,int rows,int columns){
		if(i<0 || i>rows || j<0 || j > columns
			|| board[i][j] != 'O'){
			return;
		}	
		board[i][j] = 'P';
		//上
		dfs(board, i-1, j, rows, columns);
		//下
		dfs(board, i+1, j, rows, columns);
		//左
		dfs(board, i, j-1, rows, columns);
		//右
		dfs(board, i, j+1, rows, columns);
    }
}
```
