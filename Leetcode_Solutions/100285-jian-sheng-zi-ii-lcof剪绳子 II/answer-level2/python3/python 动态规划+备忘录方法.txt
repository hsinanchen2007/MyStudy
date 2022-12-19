```
class Solution:
    def cuttingRope(self, n: int) -> int:
        if n <= 3:
            return n-1
        dict = {0:1, 1:1, 2:2}
        def cal(n):
            if n in dict:
                return dict[n]
            
            max = 0
            for k in range(1,n+1):
                res = k * cal(n-k)
                if res > max:
                    max = res

            dict[n] = max
            return max
            
        return cal(n)%1000000007
```
