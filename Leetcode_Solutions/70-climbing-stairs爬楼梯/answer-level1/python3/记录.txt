```
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:return 1
        if n == 2:return 2
        res = [1,2]
        for i in range(3,n+1):
            num1 = res.pop()
            num2 = res.pop()
            num3 = num1 + num2
            res.append(num1)
            res.append(num3)
        return res[-1]
```
