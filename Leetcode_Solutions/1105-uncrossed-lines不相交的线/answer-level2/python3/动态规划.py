### 解题思路
创建一个二维数组dp，dp[i][j]表示A[i:]和B[j:]子数组最大的划线数。
从后往前遍历，可以得到递推公示：
如果A[i] == B[j] ->  dp[i][j] = dp[i+1][j+1]
否则 ->   dp[i][j] = max(dp[i+1][j], dp[i][j+1])

最后dp[0][0]就是最大的划线数量

### 代码

```python3
class Solution:
    def maxUncrossedLines(self, A: List[int], B: List[int]) -> int:
        M, N = len(A), len(B)
        dp = [[0]*(N+1) for _ in range(M+1)]

        for i in range(M)[::-1]:
            for j in range(N)[::-1]:
                if A[i] == B[j]:
                    dp[i][j] = 1 + dp[i+1][j+1]
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1])
        return dp[0][0]
```