![image.png](https://pic.leetcode-cn.com/7b24ea1011a58b2912684a97a9e5a5312430c50c33d7600e4be01e851a28f529-image.png)


```
'''
贪心策略
时间轴以1为步长往右移动，遇到开始事件，就把从该位置开始的所有区间的终点加入小顶堆
每个时间轴上的位置都找终点在该位置后面且终点最小的会议参加
'''

from typing import List
from queue import PriorityQueue
class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        start2end = {}

        max_val = -1
        for start, end in events:
            max_val = max(max_val, end)

            if start not in start2end:
                start2end[start] = []
            start2end[start].append(end)

        min_heap = PriorityQueue()
        ans = 0
        for pos in range(1, max_val + 1):
            if pos in start2end:
                for end in start2end[pos]:
                    min_heap.put(end)

            # 找end最小的会议参加
            while min_heap.qsize() > 0:
                if min_heap.get() >= pos:
                    ans += 1
                    break

            pos += 1

        return ans
```
