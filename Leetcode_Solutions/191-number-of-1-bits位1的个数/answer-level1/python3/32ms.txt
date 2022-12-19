```
class Solution:
    def hammingWeight(self, n: int) -> int:
        str1 = bin(n)
        return(str1.count('1'))
```
