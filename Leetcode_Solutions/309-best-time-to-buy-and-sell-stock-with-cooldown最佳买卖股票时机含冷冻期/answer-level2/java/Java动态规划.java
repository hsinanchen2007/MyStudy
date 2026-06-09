Java动态规划。
注意到dp数组中的变量仅需使用一次，空间复杂度仍可降低，只需维护dp数组中可能涉及到的变量即可。
```java
执行用时 :1 ms, 在所有 Java 提交中击败了99.28%的用户。
内存消耗 :39.5 MB, 在所有 Java 提交中击败了6.30%的用户。
```
```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices == null || prices.length == 0){
            return 0;
        }
        //状态转移图：
        //       持股               不持股
        //     ↙-----、   卖出    ↙-----、
        //    持股-----↑--------→不持股---↑
        //      |
        //      |卖
        //      |出
        //      ↓
        //    冷冻期(期间什么都不能干) 
        //
        int[][] dp = new int[prices.length][3];
        //dp[i][x]第i天进入x状态（0.不持股，1.持股，2.冷冻期）
        //不持股
        dp[0][0] = 0;
        //持股
        dp[0][1] = -prices[0];
        //冷冻期
        dp[0][2] = 0;
        for(int i = 1;i < prices.length;i++){
            //第i天不持股可以从两种状态转移而来，1.第i-1天不持股，今天仍不买股票，保持不持股状态。2.冷冻期结束了，但是今天不买股票。
            dp[i][0] = Math.max(dp[i-1][0], dp[i-1][2]);
            //第i天持股可从两种状态转移而来，1.第i-1天不持股(包含昨天是冷冻期或者昨天本身就不持股)，今天买股票。2.第i-1天持股，今天不卖出，保持持股状态。
            dp[i][1] = Math.max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
            //只有第i天卖出了股票，第i天才能进入冷冻期。
            dp[i][2] = dp[i-1][1] + prices[i];
        }
        return Math.max(dp[prices.length - 1][0], dp[prices.length - 1][2]);
    }
}
```