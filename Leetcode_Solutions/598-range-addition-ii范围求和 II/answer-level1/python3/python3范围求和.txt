```
class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        rm=m
        rn=n
        for i in range(len(ops)):
            rm = min(ops[i][0],rm)
            rn = min(ops[i][1],rn)
        return rm*rn
```
