### 解题思路
1.使用dp数组来记录到此格子的最小路径和；
2.公式: dp[i][j] =  min(dp[i-1][j], dp[i][j-1]) + grid[i][j]

### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] dp = new int[m][n];
        dp[0][0] = grid[0][0];
        //初始化第0行
        for(int j=1; j<n; j++){
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }
        //初始化第0列
        for(int i=1; i<m; i++)
            dp[i][0] = grid[i][0] + dp[i-1][0];
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                dp[i][j] =  Math.min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        return dp[m-1][n-1];
    }
}
```