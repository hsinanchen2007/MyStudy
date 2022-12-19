```
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        r = 0
        n = 0
        for i in range(len(nums)):
            if nums[i] == 1:
                n+=1
                if n>r:
                    r=n
            else:
                n=0
        return r
```
