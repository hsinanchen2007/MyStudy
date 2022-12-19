### 解题思路
遍历四个边，对每个O 分别DFS；

### 代码

```java
class Solution {
    public void solve(char[][] board) {
        int m = board.length;
        if(m==0) return;
        int n = board[0].length;
        int[][] directions = {{1,0,-1,0},
                              {0,1,0,-1}};
        Stack<int[]> stack = new Stack<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m-1||j == 0||j == n-1) {
                    if (board[i][j] == 'O') {
                       stack.add(new int[]{i,j});
                    }
                }
            }
        }
        boolean[][] used = new boolean[m][n];

        while (!stack.isEmpty()){
            int[] cur = stack.pop();
            int x = cur[0];
            int y = cur[1];
            if(used[x][y]){
                continue;
            } else {
                used[x][y] = true;
            }
            for (int k = 0; k < 4; ++k) {
                int newX = x + directions[0][k];
                int newY = y + directions[1][k];
                if (newX >= m-1  || newX < 1 || newY >= n-1  || newY < 1 || board[newX][newY] != 'O') {
                    continue;
                }
                stack.add(new int[]{newX, newY});
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = used[i][j] ? 'O' : 'X';
            }
        }
    }
}
```