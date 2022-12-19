```python
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # maximum heap, size is K
        # Complexity is O(nlogK)
        res = []
        heapq.heapify(res)
        for num in nums:
            if len(res) < k:
                heapq.heappush(res, num)
            else:
                if num > res[0]: heapq.heappushpop(res, num)
        return sorted(res)[0]
```
