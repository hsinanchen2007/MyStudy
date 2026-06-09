抽象成数字后，找规律发现是每次前两个数的和，即斐波那契数列
解1、递归，求前两个数的和
解2、斐波那契通项目公式
```
import math

class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 1
        elif n == 2:
            return 2
        else:
            n = n + 1
            result = (1/math.sqrt(5)) * (((1+math.sqrt(5))/2)**n-((1-math.sqrt(5))/2)**n)
            return int(result)
```

解3、动态动态