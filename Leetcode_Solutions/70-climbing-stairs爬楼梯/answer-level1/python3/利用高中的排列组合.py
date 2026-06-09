利用公式：C(n,m)=n!/m!(n-m)!

```
class Solution:
    def fac(self, num):
        factorial = 1
        for i in range(1,num + 1):
            factorial = factorial * i
        return factorial

    def climbStairs(self, n: int) -> int:
        twostep = 0
        maxtwo = n //2
        j = 0
        while twostep <= maxtwo:
            onestep = n - 2 * twostep
            m = onestep + twostep
            j = j + self.fac(m)//(self.fac(onestep) * self.fac(twostep))
            twostep += 1
        return j
```
