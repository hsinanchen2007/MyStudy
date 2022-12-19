解题思路：有几种解题思路，最简单的就是递归了。但是递归进行了大量的重复运算，可以优化的就是将中间运算进行存储，然后去查找，这样会节省资源。
代码1：
```
class Solution:
    def fib(self, N: int) -> int:
        if N <= 1:
            return N
        return self.fib(N-1) + self.fib(N-2)
```
代码2:
```
class Solution:
    def fib(self, N: int) -> int:
        if N <= 1:
            return N
        cached = {0: 0, 1:1}
        for i in range(2, N+1):
            cached[i] = cached[i-2] + cached[i-1]
        return cached[N]
```

