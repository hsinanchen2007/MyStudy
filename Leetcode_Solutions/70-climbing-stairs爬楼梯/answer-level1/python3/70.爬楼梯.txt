解：大概都能发现n的值为n-1和n-2的值相加，所以第一时间就是递归，但是发现超时了，那就只好从低到高加上去了。
代码很简单：
```
class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 3:
            return n
        else:
            i = 3
            n1 = 3
            n2 = 2
            while i < n:
                n1,n2 = n1+n2,n1
                i += 1
            return n1
```
