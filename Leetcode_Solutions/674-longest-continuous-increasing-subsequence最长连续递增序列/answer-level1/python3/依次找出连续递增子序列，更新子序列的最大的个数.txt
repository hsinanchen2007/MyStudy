```
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        if len(nums) < 1:
            return 0
        if len(nums) == 1:
            return 1
        count = 1
        i = 0
        j = 0
        while j < len(nums)-1:
            if nums[j] < nums[j+1]:
                j += 1
                if j - i + 1 > count:
                    count = j - i + 1
            if j == len(nums) - 1:
                break
            if nums[j] >= nums[j+1]:
                i = j+1
                j = i
        return count
```
