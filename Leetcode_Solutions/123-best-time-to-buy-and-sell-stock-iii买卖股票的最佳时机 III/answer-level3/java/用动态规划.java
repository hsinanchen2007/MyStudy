### 解题思路
用动态规划

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }

        int m = prices.length;
        int[][] dp = new int[m + 1][5 + 1];

        for (int i = 2; i <= 5; i++) {
            dp[0][i] = Integer.MIN_VALUE;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= 5; j += 2) {
                dp[i][j] = dp[i - 1][j];
                if (i >= 2 && j >= 2 && dp[i - 1][j - 1] != Integer.MIN_VALUE) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + prices[i - 1] - prices[i - 2]);
                }
            }

            for (int j = 2; j <= 5; j += 2) {
                dp[i][j] = dp[i - 1][j - 1];
                if (i >= 2 && dp[i - 1][j] != Integer.MIN_VALUE) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j] + prices[i - 1] - prices[i - 2]);
                }
            }
        }

        return Math.max(dp[m][1], Math.max(dp[m][3], dp[m][5]));
    }
}
```