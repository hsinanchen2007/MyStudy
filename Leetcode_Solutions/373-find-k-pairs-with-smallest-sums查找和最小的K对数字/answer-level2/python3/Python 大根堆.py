```python
class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        heap = []
        for num1 in nums1:
            for num2 in nums2:
                if len(heap) < k:
                    heapq.heappush(heap, (-(num1 + num2) , [num1, num2]))
                else:
                    if num1 + num2 < -heap[0][0]:
                        heapq.heappushpop(heap, (-(num1 + num2), [num1, num2]))
        return [item[1] for item in heap]
```
