```
class Solution:
    def countBits(self, num: int) -> List[int]:
        res = [0]*(num+1)
        i = 1
        while i <= num:
            res[i] = 1
            for j in range(i+1, min(i*2, num+1)):
                res[j] = 1+res[j-i]
            i *= 2
        return res
```
