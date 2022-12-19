### 解题思路
还可以用快速排序（懒得写代码了，下次要用快排！）

### 代码

```python3
import heapq
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # return heapq.nlargest(k,nums)[-1]
        heapq.heapify(nums)
        
        while len(nums) > k:
            heapq.heappop(nums)
        return nums[0]
```