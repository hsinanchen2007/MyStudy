### 解题思路
python的最小堆实现

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        h = []
        for val in arr:
            heapq.heappush(h, val)
        
        return [heapq.heappop(h) for i in range(k)]
```