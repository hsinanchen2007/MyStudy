```java
class Solution {
    static final int[][] dir = {{1, 1}, {1, 0}, {0, 1}, {1, -1}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}};

    public void gameOfLife(int[][] board) {
        if (board == null || board.length == 0) return;
        gameOfLifeHelper(board, 0, board.length, board[0].length);
    }

    public void gameOfLifeHelper(int[][] board, int k, int m, int n) {
        if (k == m * n) return;
        int i = k / n, j = k % n;
        int live = 0;
        for (int[] d : dir) {
            int x = i + d[0], y = j + d[1];
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            live += board[x][y];
        }

        gameOfLifeHelper(board, k + 1, m, n);

        if (board[i][j] == 1) {
            if (live < 2 || live > 3) board[i][j] = 0;
        } else if (live == 3) {
            board[i][j] = 1;
        }
    }
}
```
