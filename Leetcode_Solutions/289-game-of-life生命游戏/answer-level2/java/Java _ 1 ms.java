### 代码

```java
class Solution {
    private int[][] marked;
    /**
     * 八个方位信息
     */
    private int[][] direction = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    /**
     * 二维数据共有多少行
     */
    private int m;
    /**
     * 二维数组共有多少列
     */
    private int n;

    private int[][] board;

    public void gameOfLife(int[][] board) {
        m = board.length;
        if (m != 0) {
            n = board[0].length;
            this.board = board;
            // 构建标记的二维数组 false 维持原值，true 翻转变化
            int[][] marked = new int[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    marked[i][j] = dfs(i, j, board[i][j]);
                }
            }
            for (int i = 0; i < m; i++) {
                if (n >= 0) {
                    System.arraycopy(marked[i], 0, board[i], 0, n);
                }
            }
        }
    }

    private int dfs(int i, int j, int boardValue) {
        int live = 0;
        for (int k = 0; k < 8; k ++) {
            int newX = i + direction[k][0];
            int newY = j + direction[k][1];
            if (isArea(newX, newY)) {
                if (board[newX][newY] == 1) {
                    live ++;
                }
            }
        }
        if (boardValue == 1) {
            if (live < 2 || live > 3) {
                return 0;
            }
        } else {
            if (live == 3) {
                return 1;
            }
        }
        return boardValue;
    }


    private boolean isArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

}
```