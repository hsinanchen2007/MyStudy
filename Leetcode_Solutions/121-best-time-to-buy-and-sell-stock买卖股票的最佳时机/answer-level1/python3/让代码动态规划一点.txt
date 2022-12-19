参考[python-by-yiwei-luo](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/python-by-yiwei-luo/)的题解，总算是感受到了动态规划的点在哪。即状态转移方程为：

`最大利润=max{前一天最大利润, 今天的价格 - 之前最低价格}`

为了表述，这里重写了一下，添加了`profit`来保存局部解，让代码更“动态规划”了一点。

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2:
            return 0

        profit = [0 for _ in range(len(prices))]
        min_p = float('inf')
        
        for i in range(len(prices)):
            profit[i] = max( profit[i-1], prices[i] - min_p)
            if min_p > prices[i]:
                min_p = prices[i]
                
        return profit[-1]
```