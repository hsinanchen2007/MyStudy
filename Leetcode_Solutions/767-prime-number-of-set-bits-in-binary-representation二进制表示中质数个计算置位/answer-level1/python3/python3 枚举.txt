```
class Solution:
    def countPrimeSetBits(self, L: int, R: int) -> int:
        res = 0
        for i in range(L,R+1):
            n = bin(i)[2:].count('1')
            if n in (2,3,5,7,11,13,17,19):
                res+=1
        return res

```
