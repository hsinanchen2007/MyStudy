### 解题思路
1. 一次遍历，双指针
2. 动态规划

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # min_price = float('inf')
        # max_profit = 0
        # for i in range(len(prices)):
        #     min_price = min(prices[i], min_price)
        #     max_profit = max(max_profit, prices[i]-min_price)
        # return max_profit

        temp = max_profit = 0
        for i in range(len(prices)-1):
            temp = max(0, prices[i+1]-prices[i]+temp)
            max_profit = max(max_profit, temp)
        return max_profit

```