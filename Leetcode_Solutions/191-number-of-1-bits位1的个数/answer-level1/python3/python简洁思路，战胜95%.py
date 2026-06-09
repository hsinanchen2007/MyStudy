```
class Solution:
    def hammingWeight(self, n: int) -> int:
        s=list(str(bin(n)))
        re=[int(i) for i in s[-1:1:-1]]
        return sum(re)
```
