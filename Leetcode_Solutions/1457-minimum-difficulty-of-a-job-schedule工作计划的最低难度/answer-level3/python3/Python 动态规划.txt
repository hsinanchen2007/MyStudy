![image.png](https://pic.leetcode-cn.com/5b3da987a528f5138320df90fce293b8c09f96aaedfd8e48027dcbf16a1e84b6-image.png)


```
'''
动态规划
dp(i, j) 表示前i种工作分成j组情况下最小总难度
'''

from typing import List
class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        if d > len(jobDifficulty):
            return -1

        dp = [[0x7fffffff for _ in range(d+1)] for _ in range(len(jobDifficulty))]
        for i in range(len(jobDifficulty)):
            for j in range(1, min(d+1, i+2)):
                if j == 1:
                    dp[i][j] = max(jobDifficulty[0:i+1])
                else:
                    k = i
                    max_val = -1
                    while True:
                        if k < j-1:
                            break

                        max_val = max(max_val, jobDifficulty[k])
                        dp[i][j] = min(dp[i][j], max_val + dp[k-1][j-1])
                        k -= 1
        return dp[len(jobDifficulty)-1][d]
```
