### 解题思路
见代码

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        思路：贪心策略, 保证每一天的收益为正，亏钱的天不管, 最后的收益即最大收益
        """
        total = 0 # 总收益
        for i in range(1, len(prices)):
            if prices[i] - prices[i-1] > 0: # 如果后一天的价格比买入的价格高，说可以盈利
                total += prices[i] - prices[i-1]
        return total
        
```