### 解题思路
此处撰写解题思路

### 代码

```python3 []
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = []
        for x in nums:
            heapq.heappush(heap, x)
            if len(heap) > k: 
                heapq.heappop(heap)
        return heapq.heappop(heap) # [5,6]  从堆中弹出最小的元素

```
```python3 []
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return heapq.nlargest(k, nums)[-1] # [6,5]
```