### 解题思路
可以用滚动数组进行优化。

### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        if (grid == null || grid.length == 0 || grid[0] == null || grid[0].length == 0) {
            return 0;
        }
        int n = grid.length;
        int m = grid[0].length;
        int[][] dp = new int[n][m];
        dp[0][0] = grid[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(i == 0 && j == 0) {
                    continue;
                }
                int t = Integer.MAX_VALUE;
                if(i > 0) {
                    t = Math.min(dp[i - 1][j], t);
                }
                if(j > 0) {
                    t = Math.min(dp[i][j - 1], t);
                }
                
                dp[i][j] = t + grid[i][j];
            }
        }

        return dp[n - 1][m - 1];
    }
}
```

优化后的代码：
```java
class Solution {
    public int minPathSum(int[][] grid) {
        if (grid == null || grid.length == 0 || grid[0] == null || grid[0].length == 0) {
            return 0;
        }
        int n = grid.length;
        int m = grid[0].length;
        int[][] dp = new int[2][m];
        dp[0][0] = grid[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(i == 0 && j == 0) {
                    continue;
                }
                int t = Integer.MAX_VALUE;
                if(i > 0) {
                    t = Math.min(dp[(i - 1)%2][j], t);
                }
                if(j > 0) {
                    t = Math.min(dp[i%2][j - 1], t);
                }
                
                dp[i%2][j] = t + grid[i][j];
            }
        }

        return dp[(n - 1)%2][m - 1];
    }
}
```
