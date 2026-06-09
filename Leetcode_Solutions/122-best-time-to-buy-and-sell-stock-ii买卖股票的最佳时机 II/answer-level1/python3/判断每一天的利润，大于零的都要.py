### 解题思路
用一个for循环来判断每一天的利润

### 代码

```python3
class Solution:
    def maxProfit(self, prices):
        def profit(prices, i):
            return prices[i + 1] - prices[i]
        res = 0
        length = len(prices)
        if length < 2:
            return 0
        for i in range(length - 1):
            pro = profit(prices, i)
            if pro >= 0:
                res = res + pro
        return res
```