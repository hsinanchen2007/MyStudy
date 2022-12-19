```
class Solution(object):
    def fib(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
        return self.fib(n-1)+self.fib(n-2)
```




备注：递归法可以解决问题，但是会超出时间限制！