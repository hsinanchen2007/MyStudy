```
public int maxProfit(int[] prices) {
        if(prices.length == 0 || prices.length == 1) return 0;
        int[][] dp = new int[prices.length][2];
        int maxProfit = 0;
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = Math.max(dp[0][0],dp[0][1]+prices[1]);
        dp[1][1] = Math.max(dp[0][1],dp[0][0]-prices[1]);
        for(int i = 2;i < prices.length;i++){
            dp[i][0] = Math.max(dp[i-1][0],dp[i-1][1]+prices[i]);
            //如果第i天是买入,前一天一定是不持有的且不能卖出的,所以只需考虑大前天
            dp[i][1] = Math.max(dp[i-1][1],dp[i-2][0]-prices[i]);
        }
        for(int i = 0;i < prices.length;i++){
            maxProfit = Math.max(maxProfit,dp[i][0]);
        }
        return maxProfit;
    }
```