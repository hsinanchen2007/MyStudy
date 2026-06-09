```
class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        i=0
        res=set()
        while x**i+1<=bound and i<20:
            res.add(x**i+1)
            j=1
            r = x**i+y**j
            while r<=bound and j<20:
                res.add(r)
                j+=1
                r = x**i+y**j
            i+=1
        return list(res)
```
