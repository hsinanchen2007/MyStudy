### 解题思路
注释清晰，代码简洁，初学容易理解

### 代码

```java
class Solution {
    public int maxValue(int[][] grid) {

        int m = grid.length, n = grid[0].length;
        int[][] dp = new int[m + 1][n + 1];

        // 初始化值
        for (int i = 0; i < m; ++i)
            dp[i][0] = 0;
        for(int i = 0; i < n; ++i)
            dp[0][i] = 0;

        /*
         * 状态转移：从左边到grid[i][j]，从上边到grid[i][j]，取两者的最大值
         * 转移方程：max { grid[i-1][j], grid[i][j-1] } + grid[i - 1][j -1]
         *  注意这里dp[i][j] 对应 grid[i-1][j-1]
         */
         int di, dj;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                di = i - 1;
                dj = j - 1;
                dp[i][j] = Math.max(dp[i][dj], dp[di][j]) + grid[di][dj];
            }
        return dp[m][n];
    }
}
```