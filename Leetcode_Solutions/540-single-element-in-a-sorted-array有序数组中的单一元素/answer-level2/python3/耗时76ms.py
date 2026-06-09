```
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n1 = len(nums)
        if n1 == 1:
            return(nums[0])
        i,j = 0,1
        while j < n1:
            if nums[i] == nums[j]:
                i += 2
                j += 2
            else:
                return(nums[i])
        return(nums[-1])
```
