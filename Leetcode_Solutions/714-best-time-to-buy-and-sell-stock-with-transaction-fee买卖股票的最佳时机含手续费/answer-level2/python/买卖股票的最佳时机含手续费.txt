#### 方法：动态规划

我们维护两个变量 $\mathrm{cash}$ 和 $\mathrm{hold}$，前者表示当我们不持有股票时的最大利润，后者表示当我们持有股票时的最大利润。

在第 $i$ 天时，我们需要根据第 $i - 1$ 天的状态来更新 $\mathrm{cash}$ 和 $\mathrm{hold}$ 的值。对于 $\mathrm{cash}$，我们可以保持不变，或者将手上的股票卖出，状态转移方程为

    cash = max(cash, hold + prices[i] - fee)

对于 $\mathrm{hold}$，我们可以保持不变，或者买入这一天的股票，状态转移方程为

    hold = max(hold, cash - prices[i])

在计算这两个状态转移方程时，我们可以不使用临时变量来存储第 $i - 1$ 天 $\mathrm{cash}$ 和 $\mathrm{hold}$ 的值，而是可以先计算 $\mathrm{cash}$ 再计算 $\mathrm{hold}$，原因是在同一天卖出再买入（亏了一笔手续费）一定不会比不进行任何操作好。

```Python [sol1]
class Solution(object):
    def maxProfit(self, prices, fee):
        cash, hold = 0, -prices[0]
        for i in range(1, len(prices)):
            cash = max(cash, hold + prices[i] - fee)
            hold = max(hold, cash - prices[i])
        return cash
```

```Java [sol1]
class Solution {
    public int maxProfit(int[] prices, int fee) {
        int cash = 0, hold = -prices[0];
        for (int i = 1; i < prices.length; i++) {
            cash = Math.max(cash, hold + prices[i] - fee);
            hold = Math.max(hold, cash - prices[i]);
        }
        return cash;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n)$，其中 $n$ 是 $\mathrm{prices}$ 数组的长度。
* 空间复杂度：$O(1)$。