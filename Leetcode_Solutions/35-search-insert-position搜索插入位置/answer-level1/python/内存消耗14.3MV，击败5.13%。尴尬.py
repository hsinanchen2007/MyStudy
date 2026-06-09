### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target in nums:
            return nums.index(target)
        nums.sort()
        if target > nums[len(nums)-1]:
            return len(nums)
        for i,v in enumerate(nums):
            if v > target:
                return i
            
```