### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxProfit(int k, int[] prices) {
        //卖出和买入之间要间隔一天，也就是三天之内最多只有一笔交易
        //一旦超过了n/3，相当于k为无数次，返回k为无数次的解法，k为无关量
        if(k > prices.length/3){
            return help(prices);
        }
        int n = prices.length;
        int[][][] dp = new int[n][k+1][2];
        for (int i = 0; i < n; i++)
        for (int j = k; j >= 1; j--) {
            if (i - 1 == -1) { 
                /* 处理 base case */
                //当i为0时
                dp[i][j][0] = 0;
                dp[i][j][1] = -prices[i];
                 }
            else{
                dp[i][j][0] = Math.max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                dp[i][j][1] = Math.max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
            }
            
}
return dp[n - 1][k][0];

    }
    public int help(int[] prices){
        int n = prices.length;
        if(n == 0){
            return 0;
        }
        int[][] dp = new int[n][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1;i<n;i++){
            dp[i][0] = Math.max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = Math.max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[n-1][0];
    }
}
```