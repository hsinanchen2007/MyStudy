### 解题思路
1、坐标矩阵
2、遍历

### 代码

```java
class Solution {
    private int[] xDirect = {0, 0, 1, 1, -1, -1, 1, -1};
    private int[] yDirect = {1, -1, 1, -1, 1, -1, 0, 0};
    private int m;
    private int n;
    private int[][] result;
    public void gameOfLife(int[][] board) {
        m = board.length;
        n = board[0].length;
        result = new int[m][n];

        traverse(board);
        for (int i = 0; i < m; i++) {
            board[i] = result[i].clone();
        }
    }
    private void traverse(int[][] board) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                change(board, i, j);
            }
        }
    }
    private void change(int[][] board, int i, int j) {
        int count = 0;
        for (int k = 0; k < 8; k++) {
            int x = i + xDirect[k];
            int y = j + yDirect[k];
            if (x < 0 || x >= m || y < 0 || y >= n) {
                continue;
            }
            if (board[x][y] == 1) {
                count++;
            }
        }
        if (board[i][j] == 1) {
            if (count < 2 || count > 3) {
                result[i][j] = 0;
            } else {
                result[i][j] = 1;
            }
        } else {
            if (count == 3) {
                result[i][j] = 1;
            }
        }
    }
}
```