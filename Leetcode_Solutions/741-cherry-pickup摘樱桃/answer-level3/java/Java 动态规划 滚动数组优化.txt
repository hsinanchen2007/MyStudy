把一来一回当作同时出发, 两条线同时从起点走向终点

```java
/**
 * 动态规划
 * 把一来一回当作同时出发, 两条线同时从起点走向终点
 * 定义状态即两条线分别走到了哪里, 三维即可
 * f[i][j][k] 表示走了 i 步, 一条线横坐标为 j, 另一条线横坐标为 k 时最大收益
 * f[i][j][k] = max{ f[i-1][j'][k'] }
 * 答案: f[n+m-1][n-1][m-1]
 * 可以使用滚动数组优化
 */
class Solution {
    public int cherryPickup(int[][] grid) {
        int n = grid.length;
        if (grid[0][0] < 0) {
            return 0;
        }
        int[][][] f = new int[2][n][n];
        f[0][0][0] = grid[0][0];
        for (int i = 1; i < n * 2 - 1; i++) {
            int now = i % 2;
            int old = 1 - now;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    f[now][j][k] = Integer.MIN_VALUE;
                    int Ax = j, Ay = i - j;
                    int Bx = k, By = i - k;
                    if (Ay < 0 || By < 0 || Ay >= n || By >= n ||
                            grid[Ax][Ay] < 0 || grid[Bx][By] < 0) {
                        continue;
                    }
                    int inc = grid[Ax][Ay] + (Ax == Bx ? 0 : grid[Bx][By]);
                    f[now][j][k] = f[old][j][k] + inc;
                    if (j > 0 && k > 0) {
                        f[now][j][k] = Math.max(f[now][j][k], f[old][j - 1][k - 1] + inc);
                    } if (j > 0) {
                        f[now][j][k] = Math.max(f[now][j][k], f[old][j - 1][k] + inc);
                    } if (k > 0) {
                        f[now][j][k] = Math.max(f[now][j][k], f[old][j][k - 1] + inc);
                    }
                }
            }
        }

        return Math.max(f[(n * 2 - 2) % 2][n - 1][n - 1], 0);
    }
}
```