### 解题思路
从边缘的O开始进行深度优先搜索，使用flag[][]记录哪些不需要改变的O，随后根据flag将其它的位置全部置为X
dfs需要满足几个条件：
1. 当前节点是O，否则退出递归；
2. 当前节点没有被访问，否则推出递归；
3. 随后根据是否存在，对上下左右四个方向进行递归；

时间：O(N*M)

空间：O(N*M)

### 代码

```java
class Solution {
    public void solve(char[][] board) {
        int row = board.length;
        if(row == 0) return;;
        int column = board[0].length;
        boolean[][] flag = new boolean[row][column];
        for(int i = 0; i < column; ++i) {
            if(board[0][i] == 'O')
                dfs(board, 0, i, flag);
            if(board[row - 1][i] == 'O')
                dfs(board, row - 1, i, flag);
        }
        for(int j = 0; j < row; ++j){
            if(board[j][0] == 'O')
                dfs(board, j, 0, flag);
            if(board[j][column - 1] == 'O')
                dfs(board, j, column - 1, flag);
        }
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < column; ++j){
                if(!flag[i][j])
                    board[i][j] = 'X';
            }
        }
    }
    private void dfs(char[][] board, int r, int c, boolean[][] flag){
        if(board[r][c] == 'O' && !flag[r][c])
            flag[r][c] = true;
        else
            return;
        if(r > 0){
            dfs(board, r - 1, c, flag);
        }
        if(r < board.length - 1){
            dfs(board, r + 1, c, flag);
        }
        if(c > 0){
            dfs(board, r, c - 1, flag);
        }
        if(c + 1 < board[0].length){
            dfs(board, r, c + 1, flag);
        }
    }
}
```