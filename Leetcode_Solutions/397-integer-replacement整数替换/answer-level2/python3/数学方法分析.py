python3 36 ms
```
class Solution:
    def integerReplacement(self, n: int) -> int:
        res = 0
        while True:
            if n == 1:
                return res
            if n == 3:
                n = 1
                res += 2
            elif n % 2 == 0:
                n = n >> 1
                res += 1
            elif n % 4 == 1:
                n = n >> 1
                res += 2
            elif n % 4 == 3:
                n = (n + 1) >> 1
                res += 2
```
