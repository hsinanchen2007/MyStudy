```
class Solution:
    def trailingZeroes(self, n: int) -> int:
        count = 0
        for m in range(1,100):
            if 5**m <= n:
                count += n // 5 ** m
            else:
                break
        return count
```
