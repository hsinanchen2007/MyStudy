### 解题思路
总体思路是从坐标(n-1，n-1)开始，出发两条线路，一个往左下部分走，一个往右上部分走。那么这个题的解就是当这两条线路都到达(0, 0)时所摘下的樱桃。

在这里 dp[x1][y1][x2]表示 第一条线处在x1,y1 第二条线处在x2,y2 时，所拿到的樱桃
具体过程见代码

### 代码

```java
class Solution {
    int[][] grid;
    int[][][] dp;
    int n;
    public int cherryPickup(int[][] grid) {
        this.grid = grid;
        this.n = grid.length;
        this.dp = new int[n][n][n];
        for (int i = 0;i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                Arrays.fill(dp[i][j], Integer.MIN_VALUE);
            }
        }
        return Math.max(0, backtrack(n - 1, n - 1, n - 1));

    }

    int backtrack(int x1, int y1, int x2 ){
        int y2 = x1 - x2 + y1;
        if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) return -1;
        if (grid[x1][y1] < 0 || grid[x2][y2] < 0) return -1;
        if (x1 == 0 && y1 == 0) return grid[x1][y1];
        if (dp[x1][y1][x2] != Integer.MIN_VALUE) return dp[x1][y1][x2];
        int res = Math.max(Math.max(backtrack(x1 - 1, y1, x2 - 1),backtrack(x1 - 1, y1, x2)), Math.max(backtrack(x1, y1 - 1, x2), backtrack(x1, y1 - 1, x2 - 1)));
        if (res < 0) return dp[x1][y1][x2] = -1;
        res += grid[x1][y1];
        if (x1 != x2) res += grid[x2][y2];
        return dp[x1][y1][x2] = res;
    }
}
```