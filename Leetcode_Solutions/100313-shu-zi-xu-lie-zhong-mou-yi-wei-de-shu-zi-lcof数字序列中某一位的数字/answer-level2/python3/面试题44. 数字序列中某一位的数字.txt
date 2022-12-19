[第N个数字原题](https://leetcode-cn.com/problems/nth-digit/)

```python []
class Solution:
    def findNthDigit(self, n: int) -> int:
        for i in itertools.count(1):
            t = 10 ** (i - 1)
            m = i * 9 * t
            if n <= m:
                n -= 1
                return int(str(t + n // i)[n % i])
            n -= m
```