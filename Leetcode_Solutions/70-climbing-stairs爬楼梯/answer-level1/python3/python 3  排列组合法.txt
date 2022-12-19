爬n级楼梯相当于将若干1级爬梯和2级爬梯的排列组合，最多可能有 n//2 次2级爬梯。

```
class Solution:
    def climbStairs(self, n: int) -> int:
        def factorial(n):
            """定义阶乘函数"""
            factorial = 1
            for i in range(1,n+1):
                factorial *= i
            return factorial
        sum = 0
        for i in range(n//2+1):
            sum += factorial(n-i)/(factorial(n-2*i) * factorial(i))
        return int(sum)
```
