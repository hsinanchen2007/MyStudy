### 解题思路
动态规划

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        for i in range(1, len(prices)):
            max_profit = max(max_profit, prices[i] - min(prices[:i]))
        return max_profit
```