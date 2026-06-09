### 解题思路
双指针一前一后，分别记录**当前最低价**和**当前利润**。
最后将前指针（当前价格）归零、`max(prices)`即求最大利润。



### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: # case when prices = []
            return 0
        pnt1 = 0 # poniter 1
        for pnt2 in range(1, len(prices)): # pointer 2
            if prices[pnt1] > prices[pnt2]:
                prices[pnt1] = 0
                pnt1 = pnt2
            else:
                prices[pnt2] = prices[pnt2] - prices[pnt1]
        prices[pnt1] = 0
        return max(prices)
```