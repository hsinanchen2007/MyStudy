```
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        num = 1
        num1 = 0
        i,j = 0,1
        n1 = len(nums)
        if n1 == 0:
            return(0)
        while j < n1:
            if nums[i] < nums[j]:
                num += 1
            else:
                if num > num1:
                    num1 = num
                num = 1
            i += 1
            j += 1
        if num > num1:
            return(num)
        else:
            return(num1)
```
