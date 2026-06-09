### 解题思路


### 代码

```java
class Solution {
    private int[][] move = new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    private boolean[][] marked;
    public void solve(char[][] board) {
        if (board == null || board.length == 0 || board[0] == null || board[0].length == 0) return ;
        int m = board.length;
        int n = board[0].length;
        marked = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && marked[i][0] == false)
                dfs(board, i, 0);
            if (board[i][n - 1] == 'O' && marked[i][n - 1] == false)
                dfs(board, i, n - 1);
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O' && marked[0][i] == false)
                dfs(board, 0, i);
            if (board[m - 1][i] == 'O' && marked[m - 1][i] == false)
                dfs(board, m - 1, i);
        }   
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (marked[i][j] == false && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }

    private void dfs(char[][] board, int x, int y) {
        marked[x][y] = true;
        int m = board.length;
        int n = board[0].length;
        for (int i = 0; i < 4; i++) {
            x += move[i][0];
            y += move[i][1];
            if (x >= 0 && y >= 0 && x < m && y < n) {
                if (board[x][y] == 'O' && !marked[x][y]) dfs(board, x, y);
            }
            x -= move[i][0];
            y -= move[i][1];
        }
    }
}
```