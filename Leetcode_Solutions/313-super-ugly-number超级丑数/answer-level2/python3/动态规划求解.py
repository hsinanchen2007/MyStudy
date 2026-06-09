模仿[264. 丑数 II]的题解写的

```python []
class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        # dp保存按序排列的丑数，指针分别指向primes，找出下一个丑数
        dp = [0] * n
        dp[0] = 1
        size = len(primes)
        pos = [0] * size

        for i in range(1, n):
            _min = sys.maxsize
            for j in range(size):
                _min = min(_min, primes[j] * dp[pos[j]])

            for j in range(size):
                if _min == dp[pos[j]] * primes[j]:
                    pos[j] += 1
            dp[i] = _min
        return dp[n - 1]
```

