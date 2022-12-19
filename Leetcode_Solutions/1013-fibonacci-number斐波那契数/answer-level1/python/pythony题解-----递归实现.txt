```
class Solution(object):
    def fib(self, N):
        """
        :type N: int
        :rtype: int
        """
        if N == 1:
            return 1
        if N == 0:
            return 0
        return self.fib(N-1) + self.fib(N-2)
```
