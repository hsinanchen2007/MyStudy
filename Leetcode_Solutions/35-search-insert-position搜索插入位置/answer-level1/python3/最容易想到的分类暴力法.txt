```
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target in nums:
            return nums.index(target)
        else:
            for i in nums:
                if target<i:
                    return nums.index(i)
        return len(nums)
```
- 时间复杂度O(n)