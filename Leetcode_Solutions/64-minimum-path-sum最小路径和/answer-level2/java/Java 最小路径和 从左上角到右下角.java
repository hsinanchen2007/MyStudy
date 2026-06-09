### 解题思路
直接根据上和左节点的最小路径和，加上当前节点的值即可：
dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
注意：需要初始化第一行和第一列的结果

### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] dp = new int[rows][cols];

        dp[0][0] = grid[0][0];
        for (int i = 1; i < rows; i++) {
            // 初始化第一列
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < cols; i++) {
            // 初始化第一行
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                // 后续计算直接根据上和左节点的最小路径和，加上当前节点的值即可
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[rows - 1][cols - 1];
    }
}
```