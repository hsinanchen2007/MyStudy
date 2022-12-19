### 解题思路
1、题干状态：第i天，交易k次，第i天买入或卖出；总共三个状态。
2、求解问题为利润最大化：想办法用最少的状态来数学描述该问题。
dp[i][j][0] = Math.max(dp[i - 1][j][0], dp[i-1][j][1] + prices[i]);
dp[i][j][1] = Math.max(dp[i - 1][j][1], dp[i-1][j - 1][0] - prices[i]);
3、根据数学描述初始化变量；描述边界条件。

4、由于在k很大的时候会导致内存使用过高，所以要考虑k教大时状态转移方程是否可以更改。
dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] - prices[i]);


### 代码

```java
class Solution {
    public int maxProfit(int k, int[] prices) {
        //边界
        if(k < 1 || prices.length < 2) {
            return 0;
        }
        if(k > prices.length/2) {
            return maxProfit(prices);
        }

        //初始化
        int[][][] dp = new int[prices.length][k][2];
        for(int i = 0; i < k; i++) {
            dp[0][i][1] = -prices[0];
            dp[0][i][0] = 0;
        }
        for(int i = 0; i < prices.length; i++) {
            dp[i][0][0] = 0;
            if(i != 0) {
                dp[i][0][1] = Math.max(dp[i - 1][0][1], -prices[i]);
            }
        }

        //主逻辑
        for(int i = 1; i < prices.length; i++){
            for(int j = 0; j < k; j++) {
                dp[i][j][0] = Math.max(dp[i - 1][j][0], dp[i-1][j][1] + prices[i]);
                if(j != 0) {
                    dp[i][j][1] = Math.max(dp[i - 1][j][1], dp[i-1][j - 1][0] - prices[i]);
                }
            }
        }

        return dp[prices.length - 1][k - 1][0];
    }

    private int maxProfit(int[] prices) {
        //初始化
        int[][] dp = new int[prices.length][2];
        dp[0][1] = -prices[0];
        dp[0][0] = 0;

        //主逻辑
        for(int i = 1; i < prices.length; i++) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        
        return dp[prices.length - 1][0];
    }
}
```