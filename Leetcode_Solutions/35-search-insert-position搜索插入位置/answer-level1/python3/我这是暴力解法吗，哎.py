```
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target in nums:
            return nums.index(target)
        else:
            nums.append(target)
            i = len(nums) - 1
            while i > -1:
                if nums[i] < nums[i-1]:
                    nums[i], nums[i-1] = nums[i-1], nums[i]
                    i -= 1
                else:
                    break
            if i < 0:
                return 0
            else:
                return i
        
```
