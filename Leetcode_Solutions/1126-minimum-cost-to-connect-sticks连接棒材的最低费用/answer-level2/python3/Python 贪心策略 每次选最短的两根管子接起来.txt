![image.png](https://pic.leetcode-cn.com/b520f6733493ad0717fa0972bdc8157df6168ae21a64fff1f216bffda622c4d1-image.png)


```
'''
贪心策略 每次选最小的两根管子接起来
'''

from typing import List
from queue import PriorityQueue
class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        min_heap = PriorityQueue()
        for val in sticks:
            min_heap.put(val)

        cost = 0
        while min_heap.qsize() > 1:
            l1 = min_heap.get()
            l2 = min_heap.get()

            cost += l1 + l2
            min_heap.put(l1 + l2)
        return cost
```
