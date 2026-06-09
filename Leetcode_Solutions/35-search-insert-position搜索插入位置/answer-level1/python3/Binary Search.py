### 解题思路
二分查找， 复杂度O（log n）

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target <= nums[0]: return 0
        low = 0
        high = len(nums) - 1
        while low <= high:
            mid = (low + high) // 2
            guess = nums[mid]
            if guess < target:
                low = mid + 1
            else:
                high = mid - 1
        return low