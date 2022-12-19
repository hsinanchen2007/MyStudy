```
class Solution:
    def fib(self, N: int) -> int:
        if N ==0:
            return 0
        elif N==1:
            return 1
        else:
            s=Solution.fib(self,N-1)+Solution.fib(self,N-2)          
        return s
```
