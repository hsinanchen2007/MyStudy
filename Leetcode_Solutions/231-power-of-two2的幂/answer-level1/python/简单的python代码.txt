```
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 0:
            return False
        if n == 1:
            return True

        res = 1
        while res < n:
            res *= 2  # 改成 res <<= 1 也是可以的

        if res == n:
            return True
        else:
            return False

```
