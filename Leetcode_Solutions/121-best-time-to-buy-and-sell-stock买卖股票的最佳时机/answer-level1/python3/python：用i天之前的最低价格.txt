### 解题思路
此处撰写解题思路
1. 遍历数组中每天股票的价格，找出第i天之前的最低价格
2. 用第i天的价格减去第i天之前的最低价格 = 第i天卖出的最高收益
3. 对最高收益求最大值 = 可以获取的最高收益
### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = int(1e9)
        max_profit = 0
        for i in prices:
            max_profit = max(max_profit,i -min_price)
            min_price = min(min_price, i)
        return max_profit   
```