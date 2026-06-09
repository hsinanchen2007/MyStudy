```
class Solution:
    def climbStairs(self, n: int) -> int:
        # 斐波那契数列
        res = [0, 1, 2]
        while len(res) <= n:
            res.append(res[-1] + res[-2])
        return res[n]
```
