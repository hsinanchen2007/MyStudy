```
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        return sum((1-int(n))*2**i for i,n in enumerate(list(bin(N)[2:])[::-1]))
```
