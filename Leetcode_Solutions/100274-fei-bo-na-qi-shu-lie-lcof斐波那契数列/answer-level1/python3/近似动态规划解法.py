```
class Solution:
    def fib(self, n: int) -> int:
        if (n==0):
            return 0
        elif (n==1):
            return 1
        else:
            pre1 = 0
            pre2 = 1
            cur = 0
            for i in range(n-1):
                cur = pre1 + pre2
                pre1,pre2 = pre2 ,cur
            return cur  

```
时间复杂度：O(n)
空间复杂度:O(1)