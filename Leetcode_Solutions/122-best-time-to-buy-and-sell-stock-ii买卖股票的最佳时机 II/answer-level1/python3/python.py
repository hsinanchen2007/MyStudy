121.买卖股票的最佳时机 I
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)<=1: return 0
        diff=[0 for _ in range(len(prices)-1)]
        for i in range(len(prices)-1):
            diff[i] = prices[i+1]-prices[i]
        temp = max_profit = 0
        for i in range(len(prices)-1):
            temp = max(0,diff[i]+temp)
            max_profit = max(max_profit,temp)
        return max_profit
```

122.买卖股票的最佳时机 II
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        for i in range(1,len(prices)):
            if prices[i]>prices[i-1]:
                res+=(prices[i]-prices[i-1])
        return res
```
