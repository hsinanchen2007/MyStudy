### 解题思路
将k穷举

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int k = 2;
        int n =  prices.length;
        if(n == 0){
            return 0;
        }
        int[][][] dp = new int[n][3][2];
        dp[0][1][0] = 0;
        dp[0][1][1] = -prices[0];
        dp[0][2][0] = 0;
        dp[0][2][1] = -prices[0];
        for(int i = 1;i<n;i++){
            dp[i][1][0] = Math.max(dp[i-1][1][0], dp[i-1][1][1] + prices[i]);
            dp[i][1][1] = Math.max(dp[i-1][1][1], - prices[i]);
            dp[i][2][0] = Math.max(dp[i-1][2][0], dp[i-1][2][1] + prices[i]);
            dp[i][2][1] = Math.max(dp[i-1][2][1], dp[i-1][1][0] - prices[i]);
        }
        return dp[n-1][k][0];
    }
}
```