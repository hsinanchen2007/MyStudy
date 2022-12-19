```python
def integerBreak(n):
    """
        1. dp问题: dp[i] = max(dp[i], max(dp[i-j], i-j)*j)
            0<i<n+1, 0<j<i
        dp[i]代表数值i的乘积最大值, 它要么等于自身, 要么进行分解,
            分解为dp[i-j], i-j中的最大值 * j
    """
    if n == 1:
        return 1
    dp = [0 for _ in range(n + 1)]
    for i in range(2, n+1):
        for j in range(1, i):
            dp[i] = max(dp[i], max(dp[i-j], i-j) * j)
    return dp[-1]

print(integerBreak(10))
```