### 解题思路
就一个地方稍微注意，就是如果要买的话需要从前一天来买。

### 代码

```java
class Solution {
  public int maxProfit(int[] prices) {
      if (prices.length<=1) return 0;
        /**
         * 2维dp,
         * i表示第几天
         *
         * 0 表示持有
         * 1 表示不持有
         *
         */
        int[][] dp = new int[prices.length][2];
        for (int i = 0; i < prices.length; i++) {
            if (i == 0) {
                dp[0][0] = -prices[0];
                continue;
            }
            if (i==1){
                dp[i][0]=max(- prices[i],  dp[i - 1][0]);
                dp[i][1]= max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
                continue;
            }
            dp[i][0] = max(dp[i - 2][1]- prices[i],  dp[i - 1][0]);
            dp[i][1]= max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            
        }
        return dp[prices.length-1][1];
    }


    private int max(int a, int b) {
        return Math.max(a, b);
    }
}
```