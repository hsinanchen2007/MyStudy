dp[k][s]代表掷k个骰子时和为s的方法数，当i符合0 < s - i < s，1 <= i <= f条件时，dp[k][s]等于符合条件的dp[k - 1][s - i]之和，当1 <= n <=f 时，dp[1][n] = 1 ，其他情况都是0，运算的时候取模就行，python支持大数运算，也可以最后再取模。

```python []
class Solution:
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        dp = collections.defaultdict(int)
        def dpf(k, s):
            if (k, s) in dp or k <= 0 or s <= 0:
                return dp[(k, s)]
            if k == 1 and s <= f:
                return 1
            for i in range(1, f + 1):
                dp[(k, s)] += dpf(k - 1, s - i)
            return dp[(k, s)]
        return dpf(d, target) % (10 ** 9 + 7)
```
