### 解题思路
暴力遍历所有元素

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        inf = int(1e9)
        maxprofit = 0
        minprice = inf
        for price in prices:
            maxprofit = max(maxprofit, price - minprice)
            minprice = min(price, minprice)
        return maxprofit

```