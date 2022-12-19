如下所示，当累计利润为正时一直累加，反之累计利润清零，同时检索利润最大值。
优于暴力解法，但比较官方历史最低价格的方法稍有不足。
```
class Solution {
    public int maxProfit(int[] prices) {
        int max = 0;
        int profit = 0;
        for(int i = 0; i < prices.length-1; i++){
            int tmp = prices[i+1]-prices[i];
            if(tmp > -profit) {
                profit += tmp;
                if(profit > max) max = profit;
            }
            
            else{
                profit = 0;
            }
        }
        return max;
    }
}
```
