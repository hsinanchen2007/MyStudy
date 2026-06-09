
```
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        j=int((c)**0.5)
        for i in range(0,j+1):
            if i**2+j**2==c:
                return True
            elif i**2+j**2>c:
                j-=1
            else:
                i+=1
        return False`
```
