```python
def numsSameConsecDiff(N, K):
    """
        1. dp问题: dp[i] = dp[i-1] * 10 + dp[i-1][-1] +/- K.
        其中dp[i-1][-1]代表dp[i-1]的个位数, +/- K代表对K的加减.
    """
    dp = range(10)
    for _ in range(N-1):
        _dp = set()
        for x in dp:
            for y in [x % 10 + K, x % 10 - K]:
                if x and 0 <= y <= 9:
                    _dp.add(x * 10 + y)
        dp = _dp
        
    return list(dp)

print(numsSameConsecDiff(3,7))
```