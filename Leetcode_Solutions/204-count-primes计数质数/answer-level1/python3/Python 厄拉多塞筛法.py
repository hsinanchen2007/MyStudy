```python []
class Solution:
    def countPrimes(self, n: int) -> int:
        count = 0
        sign = [1] * n
        for i in range(2, n, 1):
            if int(sign[i]):
                count += 1
                for j in range(2 * i, n, i):
                    sign[j] = 0
        return count
```
