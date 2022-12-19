记忆化
```
class Solution:
    def fib(self, n: int) -> int:
        d = dict()
        d[0] = 0
        d[1] = 1
        for i in range(2, n+1):
            d[i] = d[i-1] + d[i-2]
        res = d[n] % 1000000007
        return res
```

dp:
```
class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        a = 0
        b = 1
        temp = 0
        for i in range(2, n+1):
            temp = a + b
            a = b
            b = temp
        return b % 1000000007
```
