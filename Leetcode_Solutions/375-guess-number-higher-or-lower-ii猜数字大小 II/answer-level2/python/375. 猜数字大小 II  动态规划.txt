### 代码

```python
class Solution(object):
    def getMoneyAmount(self, n):
#dp[i][j]表示从i到j能找到正确数字所需要的最小代价
        dp = [[n*(n+1)] * n for _ in range(n)]
#当只有一个数字时，显然无需代价
        for i in range(n):
            dp[i][i] = 0
        r = 0
        j = 1
        new_n = n - 1
#按照对角线方向依次添加数字构造dp[i][j]
        while new_n > 0:
            for i in range(r,j + 1):
                if i == r:
                    dp[r][j] = min(dp[r][j],i + 1 + dp[i+1][j])
                elif i == j:
                    dp[r][j] = min(dp[r][j],i + 1 + dp[r][i-1])
                else:
                    dp[r][j] = min(dp[r][j],max(dp[r][i-1] + i + 1,dp[i+1][j] + i + 1))
            r += 1
            j += 1
            if j == n:
                r = 0
                new_n -= 1
                j = n - new_n
        return dp[0][-1]

```