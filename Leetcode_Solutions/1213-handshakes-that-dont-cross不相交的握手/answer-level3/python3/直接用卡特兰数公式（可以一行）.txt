无论是自己分析找出递归还是直接看前几项都明显是卡特兰数，那么就直接输入公式就行，可以直接用math库的阶乘，比赛时我的代码如下，也可以直接一行返回。
```
class Solution:
    def numberOfWays(self, num_people: int) -> int:
        n=num_people//2
        from math import factorial
        return (factorial(2*n)//factorial(n)//factorial(n)//(n+1))%(10**9+7) 

```


