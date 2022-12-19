![image.png](https://pic.leetcode-cn.com/59fc1a63e9379e03fe187479299468d668ffb869f5dbc39cdd14c45b20762798-image.png)


```
'''
动态规划
dp[j] 表示以第j列为开始列的最长递增列的个数
'''

from typing import List
class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        m, n = len(A), len(A[0])

        dp = [1 for _ in range(n)]
        dp[n-1] = 1
        for j in range(n-2, -1, -1):
            for jj in range(j+1, n):
                flag = True
                for i in range(m):
                    if A[i][jj] < A[i][j]:
                        flag = False
                        break
                if flag:
                    dp[j] = max(dp[j], 1 + dp[jj])

        return n - max(dp)
```
