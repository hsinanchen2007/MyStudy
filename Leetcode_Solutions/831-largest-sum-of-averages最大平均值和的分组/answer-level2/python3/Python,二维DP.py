### 解题思路
参考官方的DP递推公式

### 代码

```python3
class Solution:
    def largestSumOfAverages(self, A: List[int], K: int) -> float:
        N = len(A)
        p = [0]
        for i in A: p.append(p[-1] + i)
        def avg(i, j):
            return (p[j] - p[i]) / float(j - i)
        dp = [[0.0 for _ in range(N+1)] for _ in range(K+1)]
        for i in range(1, N+1):
            dp[1][i] = avg(0, i)
        for k in range(2, K+1):
            for i in range(k, N+1):
                for j in range(k-1, i):
                    dp[k][i] = max(dp[k][i], dp[k-1][j] + avg(j, i))
        return dp[-1][-1]
```