### 解题思路
dp[i][j]是到当前节点的最大值
状态转移方程为：
dp[i][j] = Math.min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
考虑下i > 0 || j > 0 || i == 0 && j == 0
的边界条件即可
### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        //bad-case
        if (grid.length == 0 || grid[0].length == 0) {
            return 0;
        }

        //行
        int rows = grid.length;
        //列
        int cols = grid[0].length;

        //二维动态规划
        int[][] dp = new int[rows][cols];

        //动态转移方程
        //dp[i][j] = Math.min(dp[i-1][j], dp[i][j-1]) + grid[i][j];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i > 0 && j > 0) {
                    dp[i][j] = Math.min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                } else if (i > 0) {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                } else if (j > 0) {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                } else {
                    dp[i][j] = grid[0][0];
                }
                
            }
        }

        return dp[rows-1][cols-1];
    }
}
```