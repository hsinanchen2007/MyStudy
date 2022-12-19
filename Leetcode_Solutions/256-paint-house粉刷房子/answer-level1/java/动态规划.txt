### 解题思路
没啥好讲的

### 代码

```java
class Solution {
    public int minCost(int[][] costs) {
        int row = costs.length;
        if (row == 0) return 0;
        int[][] dp = new int[row][3];
        for (int i = 0; i < 3; i++) dp[0][i] = costs[0][i];
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < 3; j++) {
                if (j == 0) dp[i][j] = Math.min(dp[i - 1][1], dp[i - 1][2]) + costs[i][j];
                if (j == 1) dp[i][j] = Math.min(dp[i - 1][0], dp[i - 1][2]) + costs[i][j];
                if (j == 2) dp[i][j] = Math.min(dp[i - 1][0], dp[i - 1][1]) + costs[i][j];
            }
        }
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < 3; i++) {
            res = Math.min(res, dp[row - 1][i]);
        }
        return res;
    }
}
```