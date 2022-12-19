```
class Solution:
    def climbStairs(self, n: int) -> int:
        def mul(a,b):
            return [[a[0][0]*b[0][0]+a[0][1]*b[1][0],a[0][0]*b[0][1]+a[0][1]*b[1][1]],
                    [a[1][0]*b[0][0]+a[1][1]*b[1][0],a[1][0]*b[0][1]+a[1][1]*b[1][1]]]
        def power(x,n):
            y =[[1,0],[0,1]]
            while n>0:
                if n%2==0:
                    x = mul(x,x)
                    n = n//2
                y = mul(y,x)
                n-=1
            return y
        if n<=1:
            return 1
        x = [[1,1],[1,0]]
        return sum(power(x,n-1)[0])
            
        
```
