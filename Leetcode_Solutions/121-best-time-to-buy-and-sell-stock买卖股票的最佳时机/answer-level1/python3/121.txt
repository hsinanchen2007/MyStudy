### 解题思路
1、处理特殊情况：prices为空或长度为1，均返回0；
2、定义最小价格（初始化为prices[0]）和最大利润（初始化为0）两个参数；
3、遍历list，不断更新最小价格（prices[i]与当前最小价格的最小值）和最大利润（prices[i]-最小价格和当前最大利润的最大值）；
4、返回最大利润。

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0 or len(prices) == 1:
            return 0
        min_price = prices[0]
        max_profit = 0
        for i in range(len(prices)):
            min_price = min(prices[i], min_price)
            max_profit = max(prices[i] - min_price, max_profit)
        return max_profit
```