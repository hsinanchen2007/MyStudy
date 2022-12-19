```
class Solution:
    def sumNums(self, n: int) -> int:
        res = 0
        for i in range(n+1):
            res += i
        return res
```
执行用时：36 ms
内存消耗：13.4 MB