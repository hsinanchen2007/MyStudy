```
class Solution:
    def integerBreak(self, n: int) -> int:
        vs=[0,0,1,2,4,6,9]
        if n<7:
            return vs[n]
        left,mid,right=4,6,9
        cur=0
        for i in range(7,n+1):
            cur=max(left*3,mid*2)
            left,mid,right=mid,right,cur
        return cur
        
```
