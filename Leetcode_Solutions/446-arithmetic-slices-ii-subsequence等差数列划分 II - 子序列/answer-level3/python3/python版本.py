模仿官方题解写出来的
```
from typing import *
from collections import defaultdict
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        n=len(A)
        maps=[defaultdict(lambda :0) for _ in range(n)]
        total=0
        for i in range(1,n):
            for j in range(i):
                add_val=(maps[j][A[i]-A[j]]+1)
                maps[i][A[i]-A[j]]+=add_val
                total+=add_val-1
        return total
```
