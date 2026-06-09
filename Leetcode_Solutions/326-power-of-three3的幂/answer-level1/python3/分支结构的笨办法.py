```python []
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n == 1 or n == 3:
            return True
        elif n < 3:
            return False
        else:
            while (n >= 3):
                if (n % 3) == 1 or (n % 3) == 2:
                    return False
                n = n // 3
                if n == 3:
                    return True
                if n ==1 or n == 2:
                    return False
```
