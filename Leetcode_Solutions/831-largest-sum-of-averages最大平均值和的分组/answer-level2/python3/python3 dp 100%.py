中等题，状态一眼就能看出来，重在表达转移，转移的条件其实都很清楚，就是加每一步的平均值，表达好就行了

```
class Solution:
    def largestSumOfAverages(self, A: List[int], K: int) -> float:
        N = len(A)
        dp = [[0]*N for _ in range(K)]
        for j in range(N-K+1):
            dp[0][j] = sum(A[:j+1])/(j+1)
        for i in range(1, K):
            for j in range(i, N-K+i+1):
                for p in range(i-1, j):
                    dp[i][j] = max(dp[i-1][p] + sum(A[p+1:j+1])/(j-p), dp[i][j])
        return dp[-1][-1]
```

![image.png](https://pic.leetcode-cn.com/a9d51a14e9a8b6d87e4ddf10789a1cde0623e2a15c63eb91bd28c3d639d1f735-image.png)
