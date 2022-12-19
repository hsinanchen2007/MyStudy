
## 1. 二维dp
```
class Solution {
    public int maxValue(int[][] grid) {
        // 二维dp 空间O(mn)
        int m = grid.length, n = grid[0].length;
        int[][] dp = new int[m+1][n+1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
            }
        }
        return dp[m][n];
    }
}
```
---
## 2. 一维dp
```
class Solution {
    public int maxValue(int[][] grid) {
        // 一维dp 空间O(n)       
        int m = grid.length, n = grid[0].length;
        int[] dp = new int[n+1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[j] = Math.max(dp[j-1], dp[j]) + grid[i-1][j-1];
            }
        }
        return dp[n];
    }
}
```
---
## 3. 原地修改
```
class Solution {
    public int maxValue(int[][] grid) {
        // 原地修改 空间O(1)
        int m = grid.length, n = grid[0].length;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(i == 0 && j == 0)
                    continue;
                else if(i == 0 && j != 0)  // 第一行
                    grid[i][j] = grid[i][j-1] + grid[i][j];
                else if(i != 0 && j == 0)  // 第一列
                    grid[i][j] = grid[i-1][j] + grid[i][j];
                else
                    grid[i][j] = Math.max(grid[i][j-1], grid[i-1][j]) + grid[i][j];
            }
        }
        return grid[m-1][n-1];
    }
}
```



