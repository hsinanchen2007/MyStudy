
解题思路：
要求解出最大的利润，则需要保证股票在每个上涨日都盈利，每个下降日都不交易。所以，根据贪心算法的思想，由于每一天前后不影响，
则只需要对每一天的盈利做出最优选择。如果股票相对于前一天上涨，则产生利润，若相对于前一天不变或小于前一天，则利润为0。

解题代码：
```
class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        for(int i = 1; i < prices.length; i ++){
            int tmp = prices[i] - prices[i-1];
            if (tmp > 0)
               maxProfit += tmp;
        }
        return maxProfit;
    }
}
```
