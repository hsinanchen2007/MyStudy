思路1：递归，加上lru缓存，就不用重复计算啦，加速加速
```
import functools
class Solution:
    @functools.lru_cache(None)
    def tribonacci(self, n: int) -> int:
        if n==0:return 0
        if n==1:return 1
        if n==2:return 1
        return self.tribonacci(n-1)+self.tribonacci(n-2)+self.tribonacci(n-3)
```

思路2：迭代，gogogo
```
class Solution:
    def tribonacci(self, n: int) -> int:
        if n==0:return 0
        if n==1:return 1
        if n==2:return 1
        a,b,c = 0,1,1
        while n>2:
            res = a+b+c
            a,b,c = b,c,res
            n-=1
        return res
```
