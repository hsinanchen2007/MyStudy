```python
"""
    1. dp问题, 公式为: dp[i] = dp[i - 1] + dp[i - 2].
    2. dp[0], dp[1]都为1
"""
def climbStairs(n):
    # 类似斐波拉契
    a, b = 1, 1
    while n > 0:
        a, b = b, a + b
        n -= 1
    return a

def climbStairs1(n):
    r = [0 for _ in range(n + 1)]
    r[0], r[1] = 1, 1
    for i in range(2, n + 1):
        r[i] = r[i - 1] + r[i - 2]
    return r[n]

print(climbStairs(10))
print(climbStairs1(10))
```