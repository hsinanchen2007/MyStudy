这个系列的题真是折磨人呐。首先还是要先确定需要记录几个状态值。

对于某一天来说，可能会发生的情况：

1. 第一次被买入
2. 第一次被卖出
3. 第二次被买入
4. 第二次被卖出

按题目要求，我们最重要求出的是**第二次被卖出**所能获得的最大收益。

我们分别用 4 个变量来表示这 4 种情况下所能获得的最大收益：

1. 在某天完成第一次买入的最大收益 `first_buy`
2. 在某天完成第一次被卖出的最大收益 `first_sell`
3. 在某天完成第二次被买入的最大收益 `second_buy`
4. 在某天完成第二次被卖出最大收益 `second_sell`

可以得出状态转移公式：

```
first_buy = max(first_buy, -price)
first_sell = max(first_sell, first_buy + price)
second_buy = max(second_buy, first_sell - price)
second_sell = max(second_sell, second_buy + price)
```

其中 `price` 为某天股票的价格。

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        first_buy = float('-inf')
        first_sell = 0
        second_buy = float('-inf')
        second_sell = 0
        
        for price in prices:
            first_buy = max(first_buy, -price)
            first_sell = max(first_sell, first_buy + price)
            second_buy = max(second_buy, first_sell - price)
            second_sell = max(second_sell, second_buy + price)
            
        return second_sell
```