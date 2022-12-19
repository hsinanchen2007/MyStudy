```python
import heapq


class KthLargest:
    def __init__(self, k: int, nums):
        self.pool = heapq.nsmallest(k, nums)
        self.k = k

    def add(self, val: int) -> int:
        if len(self.pool) < self.k:
            heapq.heappush(self.pool, val)
        elif val > self.pool[0]:
            heapq.heapreplace(self.pool, val)
        return self.pool[0] 
```