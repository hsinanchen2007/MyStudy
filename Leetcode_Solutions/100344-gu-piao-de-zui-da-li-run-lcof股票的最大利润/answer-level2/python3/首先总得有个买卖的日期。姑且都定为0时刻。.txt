### 解题思路
首先总得有个买卖的日期。姑且都定为0时刻。
买价越低越靠前越好。当出现更低价格时更新。
卖价虽说是越高越好，但我们只需要考虑比现在算得的最高价格高即可。

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)<=1:
           return 0
        buy=prices[0]
        profit=0
        for i in prices:
            if i<buy:
                buy=i
            profit=max(profit,i-buy)
        return profit
```