### 解题思路
这种写法不太懂的是买卖的动作可以不同步吗？
hold的取值是独立与cash的取值的很奇葩
### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        cash, hold = 0, -prices[0]

        for i in range(1, len(prices)):

            cash = max(cash, hold + prices[i] - fee)
            hold = max(hold, cash - prices[i])
        return cash
```