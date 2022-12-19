### 解题思路
利用动态规划的思路去求解这个问题，这是一个区间dp的问题。首先这个状态表示为f[l][r]，为了求出所有将LR段染成最终颜色的方式，求最少步骤。
状态变化有两种当l和最终的颜色一样的情况下，f[l][r]=f[l+1][r]+1，当染[l.k]的情况下，需要顺带染成[l， k-1] + [k+1, r]就可以了
需要注意的是，计算的时候从小到大

### 代码

```python3
class Solution:
    def strangePrinter(self, s: str) -> int:
        if not s:
            return 0
        n = len(s)
        dp = [[0]*(n+1) for i in range(n+1)]

        for i in range(1, n+1):
            for l in range(n):
                # 计算的时候保证小的已经算出来了
                if i + l - 1 < n:
                    r = l + i -1
                    dp[l][r] = dp[l+1][r] + 1
                    for k in range(l+1, r+1):
                        if s[k] == s[l]:
                            dp[l][r] = min(dp[l][r], dp[l][k-1]+dp[k+1][r])
        return dp[0][n-1]
```