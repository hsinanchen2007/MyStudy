先排序，再反转，然后输出
```
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums.sort()
        return nums[::-1][k-1]
```
