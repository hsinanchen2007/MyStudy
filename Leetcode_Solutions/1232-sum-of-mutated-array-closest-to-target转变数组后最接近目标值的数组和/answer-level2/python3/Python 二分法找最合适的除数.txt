![image.png](https://pic.leetcode-cn.com/c162a387d173b27d954ea08233523ba5004b75bd725c0dd03958327272461d04-image.png)


```
'''
二分法找最佳的除数，先找第一个让剩余和大于target的除数，
候选只可能是这个除数和这个除数减1
'''

from typing import List
class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        total = sum(arr)
        if target >= total:
            return max(arr)

        l, r = 0, max(arr)

        bound = -1
        best_val = -1
        while l <= r:
            m = l + (r - l) // 2
            val = sum([x if x <= m else m for x in arr])

            if val == target:
                return m

            if val > target:
                bound = m
                best_val = val
                r = m - 1
            else:
                l = m + 1

        val = sum([x if x <= bound-1 else bound-1 for x in arr])
        if abs(val - target) <= abs(best_val - target):
            bound = bound - 1

        return bound
```
