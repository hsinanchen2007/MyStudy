```
class Solution(object):
    def fib(self, N):
        """
        :type N: int
        :rtype: int
        """
        #暴力解法
        
        if N == 1:
            return 1
        if N == 0:
            return 0
        
        return self.fib(N-1) + self.fib(N-2)
        
        # 自上而下备的忘录解法        
        self.L = [] 
        for i in range(N):
            self.L.append(0)
        
        def Result(num):
            if num == 1:
                return 1
            if num == 0:
                return 0
            if self.L[num-1] != 0:
                return self.L[num-1]
            else:
                self.L[num-1] = Result(num-1) + Result(num-2)
                return self.L[num-1]
        return Result(N)
           
        
        #自下而上的动态规划解法
        if N == 1:
            return 1
        if N == 0:
            return 0
        a = 0
        b = 1
        result = 0
        for i in range(N-1):
            result = a + b
            a = b
            b = result
        return result
            
```
