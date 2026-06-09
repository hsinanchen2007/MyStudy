```python
class Solution:
    def fib(self, N: int) -> int:
        if N <= 1: return N
        memo = [-1] * (N + 1)
        memo[0], memo[1] = 0, 1

        def helper(N: int) -> int:
            if N <= 1: return N
            if memo[N] != -1: return memo[N]
            memo[N] = helper(N - 1) + helper(N - 2)
            return memo[N]

        return helper(N)

    def fib1(self, N: int) -> int:
        if N <= 1: return N
        pre_pre, pre = 0, 1
        for _ in range(N - 1):
            cur = pre_pre + pre
            pre_pre, pre = pre, cur
        return pre
```