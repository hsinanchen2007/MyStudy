![image.png](https://pic.leetcode-cn.com/22d6ca85ca641f500a9fcfb052d50eb24f20df6b2620e126be495c81c4865dcc-image.png)


```
'''
dp 递推

dp(i, j) 表示前i个硬币，j个面朝上的概率

dp(i, j) = (1-prob[i]) * dp(i-1, j) + prob[i] * dp(i-1, j-1)

'''

from typing import List
class Solution:
    def probabilityOfHeads(self, prob: List[float], target: int) -> float:
        n = len(prob)
        dp = [[0 for _ in range(n+1)] for _ in range(n+1)]

        dp[0][0], dp[0][1] = 1- prob[0], prob[0]
        for i in range(1, n):
            for j in range(0, min(i+2, target+1)):
                if j == 0:
                    dp[i][j] = dp[i-1][j] * (1-prob[i])
                elif j == i+1:
                    dp[i][j] = dp[i-1][j-1] * prob[i]
                else:
                    dp[i][j] = (1-prob[i]) * dp[i-1][j] + prob[i] * dp[i-1][j-1]
        return dp[n-1][target]
```
