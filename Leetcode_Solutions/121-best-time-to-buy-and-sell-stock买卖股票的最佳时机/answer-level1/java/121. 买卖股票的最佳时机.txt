### 解题思路
dp[i][0]表示当第i天没有股票时，持有的最大利润；
dp[i][1]表示当第i天持有股票时，持有的最大利润；
状态转移：
1. 第i-1天没有股票，或者第i-1天有股票，在第i天将其卖出，赚钱：
dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
2. 第i-1天有股票，或者第i-1天没有股票，在第i天买入，花钱：
dp[i][1] = Math.max(dp[i - 1][1], - prices[i]);

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length == 0){
            return 0;
        }
        int[][] dp = new int[prices.length][2];
        dp[0][0] = 0; 
        dp[0][1] = -prices[0];
        for(int i = 1; i < prices.length; i ++){
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = Math.max(dp[i - 1][1], - prices[i]);
        }
        return dp[prices.length - 1][0];
    }
}
```