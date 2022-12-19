```
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
    
        return not ('00' in bin(n)[2:] or '11' in bin(n)[2:])

```
速度更快法
```
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        n = bin(n)[2:]
        return not ('00' in n or '11' in n)
```
