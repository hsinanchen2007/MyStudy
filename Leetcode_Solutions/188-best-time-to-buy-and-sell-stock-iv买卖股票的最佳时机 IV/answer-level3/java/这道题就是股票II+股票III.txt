### 解题思路
这道题就是股票II+股票III

### 代码

```java
class Solution {
    public int maxProfit(int k, int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }

        int m = prices.length;
        //判断一种特殊情况，可以转换成股票II
        if (2 * k >= m) {
            int res = 0;
            for (int i = 1; i < m; i++) {
                if(prices[i] > prices[i - 1]){
                    res += prices[i] - prices[i - 1];
                }
            }
            return res;
        }

        //下面就是股票III
        int[][] dp = new int[2][2 * k + 2];

        for (int i = 2; i <= 2 * k + 1; i++) {
            dp[0][i] = Integer.MIN_VALUE;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= 2 * k + 1; j += 2) {
                dp[i % 2][j] = dp[(i - 1) % 2][j];
                if (i >= 2 && j >= 2 && dp[(i - 1) % 2][j - 1] != Integer.MIN_VALUE) {
                    dp[i % 2][j] = Math.max(dp[i % 2][j], dp[(i - 1) % 2][j - 1] + prices[i - 1] - prices[i - 2]);
                }
            }

            for (int j = 2; j <= 2 * k + 1; j += 2) {
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
                if (i >= 2 && dp[(i - 1) % 2][j] != Integer.MIN_VALUE) {
                    dp[i % 2][j] = Math.max(dp[i % 2][j], dp[(i - 1) % 2][j] + prices[i - 1] - prices[i - 2]);
                }
            }
        }

        int res = Integer.MIN_VALUE;
        for (int i = 1; i <= 2 * k + 1; i += 2) {
            res = Math.max(res, dp[m % 2][i]);
        }
        return res;
    }
}
```