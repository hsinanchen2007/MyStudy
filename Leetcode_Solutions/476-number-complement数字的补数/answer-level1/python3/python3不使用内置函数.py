```python []
class Solution:
    def findComplement(self, num: int) -> int:
        i = 0
        z = 0
        while num > 0:
            b = num % 2
            num = num // 2
            z += (1 - b) * 2 ** i
            i += 1
        return z
```

