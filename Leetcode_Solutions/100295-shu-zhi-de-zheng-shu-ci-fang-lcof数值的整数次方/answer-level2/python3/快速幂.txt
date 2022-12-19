```
class Solution:
    def myPow(self, x: float, n: int) -> float:
        def quick(x,n):
            res = 1.0
            
            while n>0:
                if n&1==1:
                    res *= x
                    # print(res)
                x *= x
                n >>=1
            return res
    
        ans = quick(x,abs(n))
        if n<0:
            ans = 1/ans
        return ans
```
