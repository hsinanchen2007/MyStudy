```
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        he = 0
        ji = 1
        for i in str(n):
            he += int(i)
            ji *= int(i)
        return ji-he
```
