```
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        if len(nums)==1:
            return 1
        maxLen = 1
        length = 1
        for i in range(len(nums)-1):
            if nums[i+1]>nums[i]:
                length += 1
            else:
                if length>maxLen:
                    maxLen = length
                length = 1
        return max(maxLen, length)
```
