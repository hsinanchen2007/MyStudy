将问题分解成菲薄哪些函数吧
```
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2
        reslist = []
        reslist.append(0)
        reslist.append(1)
        reslist.append(2)
        for i in range(3, n+1):
            reslist.append(reslist[i-1] + reslist[i-2])
        return reslist[n]
```