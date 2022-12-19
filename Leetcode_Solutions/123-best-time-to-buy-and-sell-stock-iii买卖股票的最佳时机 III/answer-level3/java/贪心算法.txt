```
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length == 0) return 0;
        //第一次 买入， 卖出的利润
        int profit_1_in = - prices[0], profit_1_out = 0;
        //继第一次之后，第二次买入卖出的利润
        int profit_2_in = - prices[0], profit_2_out = 0;
        int n = prices.length;
        for (int i = 1; i < n; i++){
            profit_2_out = Math.max(profit_2_out, profit_2_in + prices[i]);
            //第二次买入后的利润， 第一次卖出的利润 - prices[i]
            profit_2_in = Math.max(profit_2_in, profit_1_out - prices[i]);
            profit_1_out = Math.max(profit_1_out, profit_1_in + prices[i]);
            //第一次买入后，利润为 -prices[i]
            profit_1_in = Math.max(profit_1_in, - prices[i]);
        }
        return profit_2_out;
    }
}
```
