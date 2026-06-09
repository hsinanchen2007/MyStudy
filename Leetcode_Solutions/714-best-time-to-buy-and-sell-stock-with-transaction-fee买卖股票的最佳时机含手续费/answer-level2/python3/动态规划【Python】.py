### 思路

**动态规划**

```
相当于在 LeetCode 0122 基础上加了手续费。

找到状态方程

dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i] - fee)
解释：昨天没有股票，昨天有股票今天卖出，同时减去交易费用（交易费用记在买或卖都可以）

dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k][0] - prices[i])
解释：昨天有股票，昨天没有股票今天买入

base case：
dp[-1][k][0] = dp[i][k][0] = 0
dp[-1][k][1] = dp[i][k][1] = -inf

k = +inf
因为 k 为正无穷，那么可以把 k 和 k-1 看成是一样的。
buy+sell = 一次完整的交易，这里把 sell 看成一次交易，所以第一行是 k-1。
dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k-1][1] + prices[i] - fee)
			= max(dp[i-1][k][0], dp[i-1][k][1] + prices[i] - fee)
dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k][0] - prices[i])

所以 k 对状态转移没有影响：
dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee)
dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])

i = 0 时，dp[i-1] 不合法。
dp[0][0] = max(dp[-1][0], dp[-1][1] + prices[i] - fee)
         = max(0, -infinity + prices[i] - fee)
         = 0
dp[0][1] = max(dp[-1][1], dp[-1][0] - prices[i])
         = max(-infinity, 0 - prices[i]) 
         = -prices[i]
```

**空间复杂度:** O(1)

##### Python3代码

```python
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        dp_i_0 = 0
        dp_i_1 = float('-inf')  # 负无穷
        for i in range(len(prices)):
            temp = dp_i_0
            # 昨天没有股票，昨天有股票今天卖出，同时减去交易费用
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i] - fee)  # dp_i_0 和 dp_i_1 可以看成是变量，存储的都是上一次即昨天的值
            # 昨天有股票，昨天没有股票今天买入
            dp_i_1 = max(dp_i_1, temp - prices[i])
        return dp_i_0	
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/0714-Best-Time-to-Buy-and-Sell-Stock-with-Transaction-Fee/0714.py)

### 参考

[一个方法团灭 6 道股票问题](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/)