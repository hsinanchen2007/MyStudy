
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

![image.png](https://pic.leetcode-cn.com/b95208f96c09aa8a2a4ea9f491bdb001a152d9124c4e817eaa9a9cd6918a2f0e-image.png)
