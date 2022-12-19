我写了个$O(N^2)$的动态规划。`ToT`

$profits[i] = prices[i] - minPrice(i, j) + profits[j]$ , `j`为上次卖出时间，`i`为这次卖出时间

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0) return 0;

        // 在第i天卖出所能获得的最大收益
        int[] profits = new int[prices.length];
        int maxProfit = 0;
        for (int i = 1; i < prices.length; ++i) {
            int minPrice = Integer.MAX_VALUE;
            profits[i] = Math.max(0, prices[i] - prices[0]);
            // 上次卖出时间
            for (int j = i-1; j >= 0; -- j) {
                int curProfit = prices[i] - minPrice + profits[j];
                if (curProfit > profits[i]) {
                    profits[i] = curProfit;
                }
                minPrice = Math.min(minPrice, prices[j]);
            }
            if (profits[i] > maxProfit) {
                maxProfit = profits[i];
            }
        }
        return maxProfit;
    }
}
}```
