### 解题思路
简单暴力。
比较相邻的两个元素。设置总利润为0
如果后面的元素大于前面的元素，把差值加入到总利中
如果后面的元素小于前面的，就放弃交易，进入下一轮

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0 
        i = 1 
        while i < len(prices):
            profit = prices[i] - prices[i-1]
            if profit > 0: 
                max_profit += profit 
            i += 1
        return max_profit
```