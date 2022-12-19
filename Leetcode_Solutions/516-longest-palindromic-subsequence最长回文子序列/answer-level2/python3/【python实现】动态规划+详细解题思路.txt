解题思路：
因为是求全局最优解，且是回文子序列，因此可以考虑`区间规划`
一、最优子结构
1. 在区间`f[0][n-1]`里，如果`s[0] == s[n-1]`，那么`f[0][n-1] = f[1][n-2] + 2`
如果`s[0] != s[n-1]`，那么`f[0][n-1] = max(f[1][n-1], f[0][n-2])`
自然地，`f[0][n-1]`被定义为：从第0~n-1个字符的最长回文子序列的数量，它依赖于优先个先前值
二、重叠子问题
根据以上的递推方程，易得存在重叠的子问题

```
class Solution:
    def longestPalindromeSubseq(self, s):
        # 特殊情况判断
        if not s:
            return 0
        
        # 定义dp：二维列表，dp[i][j]被定义为：从第i~j个字符的最长回文子序列的数量
        # 初始化dp
        dp = [[0 for _ in s] for _ in s]
        n = len(dp)
        for i in range(n):
            dp[i][i] = 1
        
        # 自底向上填表
        for i in range(n)[::-1]:  # 逆序
            for j in range(i+1, n):  # 在i之后
                # 递推方程条件
                if s[i] == s[j]:
                    if j == i+1:
                        dp[i][j] = 2
                    else:
                        dp[i][j] = dp[i+1][j-1] + 2
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        return dp[0][-1]
```