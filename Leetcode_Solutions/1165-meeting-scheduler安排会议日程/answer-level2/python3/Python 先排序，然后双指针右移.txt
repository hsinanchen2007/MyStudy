![image.png](https://pic.leetcode-cn.com/10be6c086412bcba9208dbe187e0affd03949a97097345c8098cc059cab1b427-image.png)


```
'''
先排序，然后双指针右移
'''

from typing import List
class Solution:
    def minAvailableDuration(self, slots1: List[List[int]], slots2: List[List[int]], duration: int) -> List[int]:
        slots1.sort(key=lambda x: x[0])
        slots2.sort(key=lambda x: x[0])

        i, j = 0, 0
        while i < len(slots1) and j < len(slots2):
            s1, e1 = slots1[i]
            s2, e2 = slots2[j]
            l_bound, r_bound = max(s1, s2), min(e1, e2)
            if r_bound - l_bound >= duration:
                return [l_bound, l_bound + duration]

            if e1 <= e2:
                i += 1
            else:
                j += 1
        return []
```
