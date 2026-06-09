比较典型的动态规划题，先初始化状态的边界值，然后计算其他的状态。
dp数组的三维分别表示蛇的x,y位置，和水平（0）、竖直（1）状态
```
class Solution {
public int minimumMoves(int[][] grid) {
        if (!(grid[0][0] == 0 && grid[0][1] == 0)) {
            return -1;
        }

        int n = grid.length;
        int[][][] dp = new int[n][n][2];
        dp[0][0][0] = 0;

        //初始化第一行蛇水平状态
        for (int j = 1; j < n; j++) {
            dp[0][j][0] = stepByMoveRight(0, j, grid, dp);
        }

        if (grid[1][0] == 0 && grid[1][1] == 0) {
            dp[0][0][1] = 1;
        } else {
            dp[0][0][1] = Integer.MAX_VALUE;
        }

        //初始化第一列蛇竖直状态
        for (int i = 1; i < n; i++) {
            dp[i][0][1] = stepByMoveDown(i, 0, grid, dp);
        }

        //初始化第一行蛇竖直状态
        for (int j = 1; j < n; j++) {
            int rotate1 = stepByRotateDown(0, j, grid, dp);
            int move1 = stepByParallelMoveDown(0, j, grid, dp);
            dp[0][j][1] = min(rotate1, move1);
        }

        //初始化第一列蛇水平状态
        for (int i = 1; i < n; i++) {
            int rotate1 = stepByRotateRight(i, 0, grid, dp);
            int move1 = stepByParallelMoveRight(i, 0, grid, dp);
            dp[i][0][0] = min(rotate1, move1);
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {

                //根据前面的状态计算
                int move1 = stepByMoveRight(i, j, grid, dp);
                int move2 = stepByParallelMoveRight(i, j, grid, dp);
                dp[i][j][0] = min(move1, move2);

                //根据前面的状态计算
                move1 = stepByMoveDown(i, j, grid, dp);
                move2 = stepByParallelMoveDown(i, j, grid, dp);
                dp[i][j][1] = min(move1, move2);

                //旋转的时候取最小
                int rotate = stepByRotateRight(i, j, grid, dp);
                if (dp[i][j][0] > rotate) {
                    dp[i][j][0] = rotate;
                }

                //旋转的时候取最小
                rotate = stepByRotateDown(i, j, grid, dp);
                if (dp[i][j][1] > rotate) {
                    dp[i][j][1] = rotate;
                }
            }
        }

        return dp[n - 1][n - 2][0] == Integer.MAX_VALUE ? -1 : dp[n - 1][n - 2][0];
    }

    private int min(int a, int b) {
        return a > b ? b : a;
    }

    private int increment1NotOverMax(int a) {
        return a == Integer.MAX_VALUE ? Integer.MAX_VALUE : a + 1;
    }

    /**
     * ->->
     *
     * @param x
     * @param y
     * @param grid
     * @param dp
     * @return
     */
    private int stepByMoveRight(int x, int y, int[][] grid, int[][][] dp) {
        if (y + 1 < grid.length && y - 1 >= 0) {
            return grid[x][y + 1] == 0 ? increment1NotOverMax(dp[x][y - 1][0]) : Integer.MAX_VALUE;
        }
        return Integer.MAX_VALUE;
    }

    /**
     * ->
     * ->
     *
     * @param x
     * @param y
     * @param grid
     * @param dp
     * @return
     */
    private int stepByParallelMoveRight(int x, int y, int[][] grid, int[][][] dp) {
        if (y + 1 < grid.length && x - 1 >= 0) {
            return grid[x][y] == 0 && grid[x][y + 1] == 0 ? increment1NotOverMax(dp[x - 1][y][0]) : Integer.MAX_VALUE;
        }
        return Integer.MAX_VALUE;
    }

    /**
     * ↓
     * →
     *
     * @param x
     * @param y
     * @param grid
     * @param dp
     * @return
     */
    private int stepByRotateRight(int x, int y, int[][] grid, int[][][] dp) {
        if (x + 1 < grid.length && y + 1 < grid.length) {
            return grid[x][y + 1] == 0 && grid[x + 1][y + 1] == 0 ? increment1NotOverMax(dp[x][y][1]) :
                    Integer.MAX_VALUE;

        }
        return Integer.MAX_VALUE;
    }

    /**
     * ↓
     * ↓
     *
     * @param x
     * @param y
     * @param grid
     * @param dp
     * @return
     */
    private int stepByMoveDown(int x, int y, int[][] grid, int[][][] dp) {
        if (x + 1 < grid.length && x - 1 >= 0) {
            return grid[x + 1][y] == 0 ? increment1NotOverMax(dp[x - 1][y][1]) : Integer.MAX_VALUE;
        }
        return Integer.MAX_VALUE;
    }

    /**
     * ↓↓
     *
     * @param x
     * @param y
     * @param grid
     * @param dp
     * @return
     */
    private int stepByParallelMoveDown(int x, int y, int[][] grid, int[][][] dp) {
        if (x + 1 < grid.length && y - 1 >= 0) {
            return grid[x][y] == 0 && grid[x + 1][y] == 0 ? increment1NotOverMax(dp[x][y - 1][1]) : Integer.MAX_VALUE;
        }
        return Integer.MAX_VALUE;
    }

    /**
     * →
     * ↓
     *
     * @param x
     * @param y
     * @param grid
     * @param dp
     * @return
     */
    private int stepByRotateDown(int x, int y, int[][] grid, int[][][] dp) {
        if (x + 1 < grid.length && y + 1 < grid.length) {
            return grid[x + 1][y] == 0 && grid[x + 1][y + 1] == 0 ? increment1NotOverMax(dp[x][y][0]) :
                    Integer.MAX_VALUE;
        }
        return Integer.MAX_VALUE;
    }
}
```
