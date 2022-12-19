```
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        j=int(math.sqrt(c))
        i=0
        while i <=j:
            if c==i*i+j*j:
                return True
            elif i*i+j*j>c:
                j=j-1
            else:
                i=i+1
```
