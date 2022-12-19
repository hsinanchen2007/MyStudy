
-   动态规划

-   初始化：

```
dp[i][j]：表示从第i个到第j个角所形成的三角形的最小面积
```

-   状态转换方程

```
dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[k] * A[j])
```



```python
class Solution:
    def minScoreTriangulation(self, A: List[int]) -> int:
        length = len(A)
        inf = float('inf')
        dp = [[inf for _ in range(length)] for _ in range(length)]

        for i in range(length - 1):
            dp[i][i + 1] = 0

        for d in range(2, length):
            for i in range(0, length - d):
                j = i + d
                for k in range(i + 1, j):
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[k] * A[j])

        return dp[0][length - 1]
```

-   DFS加记忆化

主要是子问题的切分，dfs更容易理解一些

```python
from functools import lru_cache


class Solution:
    def minScoreTriangulation(self, A: List[int]) -> int:
        @lru_cache(None)
        def dfs(left, right):
            if left + 1 == right:
                return 0
            ans = float('inf')
            for k in range(left + 1, right):
                ans = min(ans, dfs(left, k) + dfs(k, right) + A[left] * A[k] * A[right])

            return ans

        return dfs(0, len(A) - 1)
```


