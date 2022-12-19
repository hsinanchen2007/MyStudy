### 解题思路:

套用大佬的状态转移方程:

```
dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
                 继续空仓观望       卖出手上的股票
dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])   # dp[i - 1][0] 不能是从 dp[i - 2][1] + prices[i] 转移过来的
                 继续持有股票       买入股票
```

dp[i][1] 的状态转移问题:
如果从 i - 1 天转移的话, `dp[i - 1][0`] (第 `i - 1` 天, 手上没有股票) 中不可能是从 `dp[i - 2][1] + prices[i - 1]` (第 `i - 2` 天, 手上有股票, 这意味着是在 i - 1 天卖出了股票, 那第 i 天就是冷冻期, 不能买股票, 与 dp[i][1] 矛盾了)
`dp[i][1]` 的 max 的右半边的 `dp[i - 1][0]` 就只能等于 `dp[i - 2][0]`

-> `dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i])`

初始状态:
```
dp[0][0] = 0
dp[0][1] 不存在
dp[1][0] = 0
dp[1][1] = -prices[i]
```
答案: `dp[n][0]`

### 代码

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0

        n = len(prices)
        dp = [[0, 0] for _ in range(n + 1)]
        prices.insert(0, 0)  # 下标1算第一天, 方便处理

        dp[1][1] = -prices[1]
        for i in range(2, n + 1):
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i])

        return dp[n][0]
```