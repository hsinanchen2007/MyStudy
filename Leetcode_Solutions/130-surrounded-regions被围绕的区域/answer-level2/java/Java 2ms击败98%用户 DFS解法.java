### 解题思路
此处撰写解题思路
![图片.png](https://pic.leetcode-cn.com/fecfd5cbb20d37cf411ceac9aad3bcd76f0469845adfef39be8755ee91316ba2-%E5%9B%BE%E7%89%87.png)

**从边缘开始DFS，然后看内部哪些没有被遍历到，设置为X就行了。**
**每次DFS之前判断一下是否需要DFS可以加速。**

### 代码

```java
class Solution {
    public void solve(char[][] board) {
        if (board == null || board.length == 0 || board[0].length == 0) return;
        boolean[][] flag = new boolean[board.length][board[0].length];
        for (int i = 0; i < board.length; i++) {
            if (!flag[i][0]) dfs(board, i,0, board[i][0], flag);
            if (!flag[i][board[i].length - 1]) dfs(board, i,board[i].length - 1, board[i][board[i].length - 1], flag);
            flag[i][0] = flag[i][board[i].length - 1] = true;
        }
        for (int j = 0; j < board[0].length; j++) {
            if (!flag[0][j]) dfs(board, 0,j, board[0][j], flag);
            if (!flag[board.length - 1][j]) dfs(board, board.length - 1,j, board[board.length - 1][j], flag);
            flag[0][j] = flag[board.length - 1][j] = true;
        }
        for (int i = 0; i < flag.length; i++) {
            for (int j = 0; j < flag[i].length; j++) {
                if (!flag[i][j]) board[i][j] = 'X';
            }
        }
    }
    private void dfs(char[][] board, int i, int j, char c, boolean[][] flag){
        if (i > 0 && !flag[i - 1][j] && board[i - 1][j] == c){
            flag[i - 1][j] = true;
            dfs(board, i - 1, j, c, flag);
        }
        if (j > 0 && !flag[i][j - 1] && board[i][j - 1] == c){
            flag[i][j - 1] = true;
            dfs(board, i, j - 1, c, flag);
        }
        if (i + 1 < board.length && !flag[i + 1][j] && board[i + 1][j] == c){
            flag[i + 1][j] = true;
            dfs(board, i + 1, j, c, flag);
        }
        if (j + 1 < board[i].length && !flag[i][j + 1] && board[i][j + 1] == c){
            flag[i][j + 1] = true;
            dfs(board, i, j + 1, c, flag);
        }
    }
}
```