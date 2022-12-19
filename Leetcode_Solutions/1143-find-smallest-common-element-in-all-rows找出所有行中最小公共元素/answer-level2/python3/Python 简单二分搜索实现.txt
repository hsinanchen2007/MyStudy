![image.png](https://pic.leetcode-cn.com/e3eb585827350742b36c26e428ae34483d00676a2de18d8b546a86112871338b-image.png)


```
from typing import List
import bisect
class Solution:
    def smallestCommonElement(self, mat: List[List[int]]) -> int:
        l_bound, r_bound = -0x7fffffff, 0x7fffffff
        for l in mat:
            l_bound = max(l[0], l_bound)
            r_bound = min(l[-1], r_bound)

        for val in mat[0]:
            if val < l_bound or val > r_bound:
                continue

            flag = True
            for i in range(1, len(mat)):
                idx = bisect.bisect_left(mat[i], val)
                if not (idx >= 0 and idx < len(mat[i]) and mat[i][idx] == val):
                    flag = False
                    break

            if flag:
                return val

        return -1

```

