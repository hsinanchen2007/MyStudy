```python
def numTrees(n):
    """
        1. dp问题: dp[i] = dp[i - 1]为左子树 * dp[i+1]为右子树
    """
    dp = [0 for _ in range(n+1)]
    dp[0], dp[1] = 1, 1
    i = 2
    while i <= n:
        for j in range(i):
            # dp[j]代表0~i中, j之前的左子树, i-j-1代表j~i的右子树
            dp[i] += dp[j] * dp[i - j - 1]
        i += 1
    return dp[-1]

print(numTrees(8))
```