### 解题思路
优先队列

### 代码

```python3
import heapq
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        q = []
        for i in arr:
            heapq.heappush(q,i)
        rs = heapq.nsmallest(k, q)
        return rs
```