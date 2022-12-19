```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)<=1:
            return 0
        # 记录最低的价格
        low_price = prices[0]
        # 记录此前一天的最大利润
        
        max_profit = 0 
        for num in prices[1:]:
            # 当天的最大利润等于 前一天的最大利润和今天卖出的利润的最大值
            max_profit = max(max_profit,num-low_price)
            low_price = min(low_price,num)
        return max_profit
```
