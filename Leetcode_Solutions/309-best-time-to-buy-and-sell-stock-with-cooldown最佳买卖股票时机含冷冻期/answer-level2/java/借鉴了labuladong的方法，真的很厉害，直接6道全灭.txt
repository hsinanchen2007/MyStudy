第一天卖了之后，第三天才可以买入，那么可以写出状态方程
            dp[i][0] = Math.max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1] = Math.max(dp[i-1][1],dp[i-2][0]-prices[i]);
继续把i==0,和i==1;处理了就可以了。

```
class Solution {
    public int maxProfit(int[] prices) {
        int m= prices.length;
        if(m==0)
            return 0;
        int dp[][] = new int[m][2];
        for(int i=0;i<m;i++){
            if(i==0){
                dp[i][0]=0;
                dp[i][1]=-prices[i];
                continue;
            }
            if(i==1){
                dp[i][0]=Math.max(dp[i-1][0],dp[i-1][1]+prices[i]);
                dp[i][1]=Math.max(dp[i-1][1],dp[i-1][0]-prices[i]);
                continue;
            }
            dp[i][0] = Math.max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1] = Math.max(dp[i-1][1],dp[i-2][0]-prices[i]);
        }
        return dp[m-1][0];
    }
}
```

