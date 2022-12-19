### 解题思路
通用解法,建立一个三维数组,考虑如果次数无限的时候,就可以薅所有的羊毛啦

### 代码

```java
/*
 * Copyright (c) 2020
 * @Author:xiaoweixiang
 */
public class Solution {
    public int maxProfit(int k, int[] prices) {
        int res = 0;
        if (k >= prices.length / 2) {
            for (int i = 1; i < prices.length; i++) {
                if (prices[i] > prices[i - 1]) {
                    res += prices[i] - prices[i - 1];
                }
            }
            return res;
        }
        /**
         * i为第几天
         * j为交易次数,0-k
         * m为持有或者不持有 0为不持有,1 为持有
         */
        res = 0;
        int[][][] dp = new int[prices.length][k + 1][2];
        for (int i = 0; i < prices.length; i++) {
            for (int j = 1; j <= k; j++) {
                if (i == 0) {
                    dp[0][j][0] = 0;
                    dp[0][j][1] = -prices[0];
                    continue;
                }
                dp[i][j][0] = Math.max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = Math.max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                res = Math.max(res, dp[i][j][0]);
            }
        }
        return res;
    }
}

```