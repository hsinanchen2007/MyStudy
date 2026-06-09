### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        low, high = -1, -1
        left, right = 0, n
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] > target: right = mid
            elif nums[mid] < target: left = mid + 1
            else:
                if mid == 0 or nums[mid - 1] != target:
                    low = mid
                    break
                else:
                    right = mid
        left, right = 0, n
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] > target: right = mid
            elif nums[mid] < target: left = mid + 1
            else:
                if mid == n - 1 or nums[mid + 1] != target:
                    high = mid
                    break
                else:
                    left = mid + 1
        return low, high

```