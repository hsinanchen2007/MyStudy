### 解题思路
解题思路就是dp表。之前的股票问题参考了labuladong的文章。如果有这类问题不懂的可以去labuladong的文章中看，以及他的github中也有很多很有用的文章。
主要流程就是1.找状态转移方程 2.dp表优化 3.O(1)优化
其中状态转移方程就是暴力递归的思路，遇到这类问题先问问自己”如何达到当前状态“，例如本题中，今天结束时持有股票这个状态取决于1.今天之前买了2.之前一直没买今天买了。这就对应代码中今天所持的最大金额是今天之前买和今天买。
最后的O(1)优化是我自己加的，比如这题中209例会超时，那么超时的原因是什么？前面k为无穷大的时候或者k为2的时候为什么可以到O(1)？这点想清楚对解决这种超大测试案例是非常有帮助的。
labuladong的文章中有一句话总结的很好：计算机解决问题的方法就是枚举，我们做的只是帮助计算机更加聪明地枚举。这几天做了编辑距离、打家劫舍和股票问题后对这类问题又有了更深刻的理解。
### 代码

```python3
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if not prices:
            return 0
        n = len(prices)
        if k >= n//2:
            dp_i_0 = 0
            dp_i_1 = -prices[0]
            for i in range(1, n):
                dp_i_0 = max(dp_i_0, dp_i_1+prices[i])
                dp_i_1 = max(dp_i_1, dp_i_0-prices[i])
            return dp_i_0
        else:
            max_trans = k
            dp = [[[0 for i in range(2)] for i in range(max_trans+1)] for i in range(n)]
            for i in range(n):
                for k in range(1, max_trans+1):
                    if i == 0:
                        dp[i][k][0] = 0
                        dp[i][k][1] = -prices[i]
                    else:
                        dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+prices[i])
                        dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i])
            return dp[n-1][max_trans][0]
```