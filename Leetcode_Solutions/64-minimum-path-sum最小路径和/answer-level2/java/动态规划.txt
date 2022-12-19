> 思路：核心思路依然是动态规划。既然是求最小路径，那么在每个点最小值肯定是 min(左边，上边) 相加。

```java
class Solution {
  public int minPathSum(int[][] grid) {
    int m = grid.length,
        n = grid[0].length;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) continue;
        if (i == 0) {
          grid[i][j] += grid[i][j - 1];
        } else if (j == 0) {
          grid[i][j] += grid[i - 1][j];
        } else {
          grid[i][j] += Math.min(grid[i - 1][j], grid[i][j - 1]);
        }
      }
    }
    return grid[m - 1][n - 1];
  }
}
```