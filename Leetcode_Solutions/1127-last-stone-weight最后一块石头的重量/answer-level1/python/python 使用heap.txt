### 解题思路
此处撰写解题思路

### 代码

```python
from functools import reduce
import heapq
class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        #currentStone = stones[0]
        heap = [-stone for stone in stones]
        heapq.heapify(heap)
        while len(heap) > 1:
            w1 = heapq.heappop(heap)
            w2 = heapq.heappop(heap)
            if w1 != w2:
                heapq.heappush(heap, -abs(w1 - w2))
        if len(heap) == 0:
            return 0
        else:
            return -heap[0]

```