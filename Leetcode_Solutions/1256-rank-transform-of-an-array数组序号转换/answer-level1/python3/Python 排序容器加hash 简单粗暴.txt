![image.png](https://pic.leetcode-cn.com/476b9db09788aed67dcd9183dda16326bcd64f9e69ad10714441c7f7e01a5ae1-image.png)


```
from typing import List
from sortedcontainers import SortedSet
class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        val2pos = {}
        s = SortedSet()
        for i, val in enumerate(arr):
            if val not in val2pos:
                val2pos[val] = []
            val2pos[val].append(i)
            s.add(val)

        rank = 1
        for val in s:
            for pos in val2pos[val]:
                arr[pos] = rank
            rank += 1
        return arr
```
