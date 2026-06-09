### 二分法

- 以第i天为分界线，将`prices`分成**前后两个区间**，分别计算两区间在**最多允许一次交易**的条件下的最大利润和，即退化为121题。最后，以不同天数为分界线，遍历找到最终的最大利润。

- 还记得在解决121题时，我们采用了动态规划，从左向右遍历，用`min_price`保存到第i天为止价格的最小值，那么第i天能得到的最大利润`l2r[i]`为`max(历史最大利润, prices[i]-min_price)`。这样一来，我们可以找到**前区间**的最大利润。

- 求解**后区间**的最大利润同理。我们从右向左遍历，用`max_price`保存第i天到最后一天中的最大价格，那么从第i天到最后一天能得到的最大利润`r2l[i]`为`max(历史最大利润, max_price-prices[i])`。

- 那么，最大利润即为l2r[i]+r2l[i+1]中最大的那个。记得不要忘了只交易一次的情况，即`l2r[-1]`或者`r2l[0]`。

- 补充：
    - 如果只从前向后遍历，也可以解出后区间的最大利润。但可以试下，有O(N2)的时间复杂度。
    - 代码分为三次遍历: from left to right, from right to left and merge。如果进一步节约空间复杂度，可以把后两次遍历结合，就不必保留`r2l`数组了。

```python []
class Solution:
    def maxProfit(self, prices):
        if len(prices) <= 1:
            return 0

        # from left to right
        l2r = [0 for i in range(len(prices))]
        min_price = prices[0]
        max_profit = 0
        for i in range(1, len(prices)):
            max_profit = max(max_profit, prices[i] - min_price)
            l2r[i] = max_profit
            min_price = min(min_price, prices[i])

        # from right to left
        r2l = [0 for i in range(len(prices))]
        max_price = prices[-1]
        max_profit = 0
        for i in range(len(prices) - 2, -1, -1):
            max_profit = max(max_profit, max_price - prices[i])
            r2l[i] = max_profit
            max_price = max(max_price, prices[i])

        # merge
        max_profit = 0
        for i in range(len(prices) - 1):
            max_profit = max(max_profit, l2r[i] + r2l[i + 1])
        max_profit = max(max_profit, l2r[-1])  # max_profit = max(max_profit, r2l[0])
        return max_profit
```
复杂度分析:
- 时间复杂度:O(N)
- 空间复杂度:O(N)