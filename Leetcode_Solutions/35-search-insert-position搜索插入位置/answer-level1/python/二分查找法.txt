### 解题思路
时间复杂度：O（log（n））
空间复杂度：O（1）

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        import math
        if len(nums) == 0:
            return 0
        if target <= nums[0]:
            return 0
        elif target > nums[-1]:
            return len(nums)

        low = 0
        high = len(nums) - 1
        mid = math.floor((low + high) / 2)
        while low < high:
            if target < nums[mid]:
                high = mid
                mid = math.floor((low + high) / 2)
            elif target == nums[mid]:
                return mid
            else:
                low = mid + 1
                mid = math.floor((low + high) / 2)
        if target <= nums[low]:
            return low
        else:
            return low + 1

```