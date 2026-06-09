### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int[][] dirs = new int[][]{{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
        for (int i=0; i<board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                int alive = 0;
                for (int[] dir : dirs) {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if (x < 0 || x >= board.length || y < 0 || y >= board[0].length)
                        continue;
                    if (board[x][y] == 1 || board[x][y] == -1)
                        alive++;
                }
                if (board[i][j] == 1) {
                    if (alive < 2 || alive > 3) {
                        board[i][j] = -1;
                    }
                } else {
                    if (alive == 3) {
                        board[i][j] = 2;
                    }
                }
            }
        }
        for (int i=0; i<board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == -1)
                    board[i][j] = 0;
                else if (board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
}
```