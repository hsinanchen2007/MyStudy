### 思路

**动态规划**

```
找到状态方程

dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
解释：昨天没有股票，昨天有股票今天卖出

dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k][0] - prices[i])
解释：昨天有股票，昨天没有股票今天买入

base case：
dp[-1][k][0] = dp[i][k][0] = 0
dp[-1][k][1] = dp[i][k][1] = -inf

k = 2
因为 k 为 2，所以要对 k 进行穷举。
dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][2][1] + prices[i])
dp[i][2][1] = max(dp[i-1][2][1], dp[i-1][1][0] - prices[i])
dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
dp[i][1][1] = max(dp[i-1][1][1], -prices[i])

i = 0 时，dp[i-1] 不合法。
dp[0][1][0] = max(dp[-1][1][0], dp[-1][1][1] + prices[i])
            = max(0, -infinity + prices[i])
            = 0
dp[0][1][1] = max(dp[-1][1][1], dp[-1][1][0] - prices[i])
            = max(-infinity, 0 - prices[i]) 
            = -prices[i]
dp[0][2][0] = max(dp[-1][2][0], dp[-1][2][1] + prices[i])
            = max(0, -infinity + prices[i])
            = 0
dp[0][2][1] = max(dp[-1][2][1], dp[-1][2][0] - prices[i])
            = max(-infinity, 0 - prices[i])
            = -prices[i]
```

**空间复杂度:** O(1)

##### Python3代码

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp_i_2_0, dp_i_1_0 = 0, 0
        # dp_i_2_1, dp_i_1_1 = -prices[0], -prices[0]  # 会报错：list index out of range
        dp_i_2_1, dp_i_1_1 = float('-inf'), float('-inf')  # 负无穷
        for i in range(len(prices)):
            # 昨天没有股票，昨天有股票今天卖出
            dp_i_2_0 = max(dp_i_2_0, dp_i_2_1 + prices[i])
            # 昨天有股票，昨天没有股票今天买入
            dp_i_2_1 = max(dp_i_2_1, dp_i_1_0 - prices[i])
            # 昨天没有股票，昨天有股票今天卖出
            dp_i_1_0 = max(dp_i_1_0, dp_i_1_1 + prices[i])
            # 昨天有股票，昨天没有股票今天买入
            dp_i_1_1 = max(dp_i_1_1, -prices[i])
            
        return dp_i_2_0
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/0123-Best-Time-to-Buy-and-Sell-Stock-III/0123.py)

### 参考

[一个方法团灭 6 道股票问题](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/)