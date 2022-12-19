```python
class Solution:
    def largestSumOfAverages(self, A: List[int], K: int) -> float:
        n = len(A)
        _sum = {}  # 先计算各个段的和方便后面调用
        for i in range(n):
            now = A[i]
            _sum[i, i+1] = now
            for j in range(i+1, n):
                now += A[j]
                _sum[i, j+1] = now
        dp = {(1, i): _sum[0, i]/i for i in range(1, n+1)}  # dp[k, i] 前i个数分成k组的最大得分
        for i in range(2, n+1):
            for j in range(i, n+1):
                _max = dp[i-1, j-1] + _sum[j-1, j]
                for k in range(i-1, j-1):
                    _max = max(_max, dp[i-1, k] + _sum[k, j]/(j-k))
                dp[i, j] = _max
        return dp[K, n]
```

