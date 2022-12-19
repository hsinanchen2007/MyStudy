```python
def minSteps(n):
    """
        1. dp[i] = dp[i//j] + j, 0 < j <= n, 并且n % j == 0.
        2. 因为只有: 全选, 复制的操作, 所以肯定是倍数的关系. 假设n=11, 不会有到10后, 加1的操作.
        3. 所以, 开始要么就是加1, 直到加到可以翻倍位置, 然后不断的翻倍.
    """
    if n == 1:
        return 0
    for i in range(2, n + 1):
        if n % i == 0:
            return minSteps(n // i) + i
        
print(minSteps(123))
```