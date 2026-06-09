动态规划思想：n个骰子的和m由 n-1个骰子的m-1,m-2,m-3,m-4,m-5,m-6相加组成
             dp[n][m] = dp[n-1][m-1] + dp[n-1][m-2] + dp[n-1][m-3] + dp[n-1][m-4] + dp[n-1][m-5] + dp[n-1][m-6]

```
def twoSum(self, n: int) -> List[float]:
    if not n:  
        return []
    dp = [[0] * (6*n + 1) for _ in range(n+1)]  # dp[n][m] 代表n个骰子结果为m的情况个数
    for i in range(1, n+1):
        if i==1:                                # 如果一个骰子(n=1),dp[1][1:7]写入1
            for j in range(1, 7):
                dp[i][j] = [1]
        else:
            for j in range(i, 6i + 1):          # 如果n个骰子,dp[1][i:6i+1]写入
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j-2] + dp[i-1][j-3] + dp[i-1][j-4] + dp[i-1][j-5] + dp[i-1][j-6]
    res = dp[-1][i:]
    for i in range(len(res)):
        res[i] /= (6**n)
    return res
```
