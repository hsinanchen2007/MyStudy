### 解题思路
分治

### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums: return [-1, -1]
        left, right = 0, len(nums)-1
        while left + 1 < right:
            mid = (left + right) >> 1
            if nums[mid] >= target: 
                right = mid 
            else: 
                left = mid 
        if nums[left] == target:    lb = left
        elif nums[right] == target: lb = right
        else: return [-1, -1]
        left, right = 0, len(nums)-1
        while left + 1 < right:
            mid = (left + right) >> 1
            if nums[mid] <= target: 
                left = mid
            else: 
                right = mid 
        if nums[right] == target:  rb = right
        elif nums[left] == target: rb = left
        else: return [-1,-1]
        return [lb, rb]
```