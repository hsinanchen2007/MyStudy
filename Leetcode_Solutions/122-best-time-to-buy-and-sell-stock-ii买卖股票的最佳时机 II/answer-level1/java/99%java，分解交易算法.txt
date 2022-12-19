```
class Solution {
    public int maxProfit(int[] prices) {
        int len = prices.length;
        if(len == 0)
        {
            return 0;
        }
        int profit = 0;
        int buyprize = prices[0];
        for(int i = 1; i < len; i++)
        {
            int newprice = prices[i];
            if(newprice > buyprize)
            {
                profit += newprice - buyprize;
            }
            buyprize = newprice;
        }
        return profit;
    }
}
```
将‘一买一卖’的一笔交易分解为每天一笔交易，这样的话一个循环即可得到结果
