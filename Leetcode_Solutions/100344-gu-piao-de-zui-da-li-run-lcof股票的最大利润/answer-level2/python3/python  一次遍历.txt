### 解题思路
1 找到第i天前最低的股票价格，设为min_priinces
2 计算第i天的最大利润，max_pro=第i天价格-min_prices[i]
3 返回最大利润

#注意边界问题
### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)<=1:
            return 0   #只买进，没有卖出

        min_princes=prices[0]       #初始化最低价格
        max_pro=0                   #初始化初始利润

        for i in range(len(prices)):
            min_princes=min(min_princes,prices[i])   #找出最低买入价格
            max_pro=max(max_pro,prices[i]-min_princes)

        return max_pro
```