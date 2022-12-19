

```python []
class Solution:
    def printBin(self, num: float) -> str:
        if 0 < num < 1:
            s = '0.'
            for _ in range(30):
                num *= 2
                s += str(int(num >= 1))
                num -= int(num)
                if not num:
                    return s
        return 'ERROR'
```