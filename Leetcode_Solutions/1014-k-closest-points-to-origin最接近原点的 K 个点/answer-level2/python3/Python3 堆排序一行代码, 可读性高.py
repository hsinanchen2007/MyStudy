```python
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        return = heapq.nsmallest(K, points, key = lambda point: point[0] ** 2 + point[1] ** 2 )
```
时间复杂度 $O(NlogK)$, 空间复杂度 $O(N)$