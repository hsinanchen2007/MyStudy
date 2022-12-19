### 解题思路
此处撰写解题思路

### 代码
时间复杂度：O(n) 
空间复杂度：O(1)
```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2: return 0
        min_price = prices[0]
        max_profit = 0
        for price in prices:
            if price < min_price:
                min_price = price
            if price - min_price > max_profit:
                max_profit = price - min_price
        return max_profit
```
#### dp
时间复杂度：O(n) 
空间复杂度：O(n)
``` python3 []
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2: return 0
        min_price = prices[0]
        dp = [0] * len(prices)
        for i in range(len(prices)):
            # 第i天的最大利润= max（前一天的最大利润，今天可能的最大利润）
            dp[i] = max(dp[i-1], prices[i] - min_price)
            min_price = min(min_price, prices[i] )
        return dp[-1]
```
#### 优化空间复杂度
时间复杂度：O(n) 
空间复杂度：O(1)
```python3 []
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2: return 0
        min_price = prices[0]
        max_profit = 0
        for i in range(len(prices)):
            max_profit = max(max_profit, prices[i] - min_price)
            min_price = min(min_price, prices[i] )
        return max_profit
```