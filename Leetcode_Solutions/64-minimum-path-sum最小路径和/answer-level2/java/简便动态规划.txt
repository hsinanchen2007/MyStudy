### 解题思路
官方题解在循环中多次判断是否为左边界或上边界，代码执行时间大多在4ms-5ms之间，如果将边界值提前订好，不需要在O(n^2)时间复杂度的循环中屡次判断，运行时间在3ms-4ms

### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] dp = new int[m][n];
        dp[0][0] = grid[0][0];
        for (int i = 1;i <= Math.max(m,n)-1;i++){
            if (i < m) dp[i][0] = grid[i][0] + dp[i-1][0];
            if (i < n) dp[0][i] = grid[0][i] + dp[0][i-1];
        }

        for (int i = 1;i <= m-1;i++){
            for (int j = 1;j <= n-1;j++){
                dp[i][j] = Math.min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
}
```