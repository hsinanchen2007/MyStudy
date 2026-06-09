```
代码块
class Solution:
    def climbStairs(self, n: int) -> int:
        if n==1: return 1
        elif n==2: return 2
        else:
            li,i=[1,2],2
            while i<n:
                li.append(li[i-1]+li[i-2])
                i+=1
            return li[n-1]
```
