### 解题思路
dp数组记录状态,然后穷举.
dp的基本上都是这个原理吧

### 代码

```java
/*
 * Copyright (c) 2020
 * @Author:xiaoweixiang
 */

public class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }
        /**
         * 建立三维数组dp[i][j][k]
         * i表示第几天
         * j表示持不持有股票 0 为不持有 1为持有
         * k表示交易次数,0,1,2
         * dp[i][0][k]=dp[i-1][0][k],dp[i-1][1][k-1]+prices[i]
         * dp[i][1][k]=dp[i-1][1][k],dp[i-1][0][k-1]-prices[i]
         * 如果当天交易持
         */
        int[][][] dp = new int[prices.length][2][3];
        for (int i = 0; i < prices.length; i++) {
            for (int k = 1; k < 3; k++) {
                if (i == 0) {
                    dp[0][0][k] = 0;
                    dp[0][1][k] = -prices[0];
                    continue;
                }
                dp[i][0][k] = Math.max(dp[i - 1][0][k], dp[i - 1][1][k] + prices[i]);
                dp[i][1][k] = Math.max(dp[i - 1][1][k], dp[i - 1][0][k - 1] - prices[i]);
            }
        }
        return dp[prices.length - 1][0][2];
    }
}

```