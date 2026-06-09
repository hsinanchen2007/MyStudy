### 思路

**动态规划**

```
找到状态方程

dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
解释：昨天没有股票，昨天有股票今天卖出

dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
解释：昨天有股票，昨天没有股票今天买入

base case：
dp[-1][k][0] = dp[i][k][0] = 0
dp[-1][k][1] = dp[i][k][1] = -inf

k 如果超过 n/2，就当作是 inf 来处理。
k 如果没有超过 n/2，就列举出 k 的值。
```

**空间复杂度:** O(1)

##### Python3代码

```python
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        if k > n/2:
            # k = inf
            dp_i_0 = 0
            dp_i_1 = float('-inf')  # 负无穷
            for i in range(n):
                temp = dp_i_0
                # 昨天没有股票，昨天有股票今天卖出
                dp_i_0 = max(dp_i_0, dp_i_1 + prices[i])  # dp_i_0 和 dp_i_1 可以看成是变量，存储的都是上一次即昨天的值
                # 昨天有股票，昨天没有股票今天买入
                dp_i_1 = max(dp_i_1, temp - prices[i])
            return dp_i_0
        
        # k <= len(prices)/2
        # dp = [[[0] * 2] * (k+1)] * n  # 创建三维数组，这个有问题
        dp = [[[0] * 2 for _ in range(k+1)] for _ in range(n)]
        for i in range(n):
            for j in range(k, 0, -1):  # 逆序
                if i == 0:
                    dp[0][j][0] = 0
                    dp[0][j][1] = -prices[0]
                    continue
                # 昨天没有股票，昨天有股票今天卖出
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i])
                # 昨天有股票，昨天没有股票今天买入，这里把买入当作一次交易，所以是 j-1
                # 如果把 j-1 写在上一行代码即把卖出当作一次交易，运行结果不是正确答案，不知道是为什么
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i])
        
        return dp[n-1][k][0]
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/0188-Best-Time-to-Buy-and-Sell-Stock-IV/0188.py)

### 参考

[一个方法团灭 6 道股票问题](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/)