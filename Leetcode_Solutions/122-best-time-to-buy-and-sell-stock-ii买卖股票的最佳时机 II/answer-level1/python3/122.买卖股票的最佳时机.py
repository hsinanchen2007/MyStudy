### 解题思路
- 多次买入卖出收益之和
- 相当于求股票曲线的所有递增区间之和
- 遍历一遍列表，当前值小于下一时刻值，则在收益中加上差值；遍历结束收益也已全部计入；
### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        for index in range(len(prices)-1):
            if prices[index] < prices[index+1]:
                res = res + prices[index+1] - prices[index]
        return res


```