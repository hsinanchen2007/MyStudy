```
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n1 = len(nums)
        if n1 == 1:
            return(0)
        num1 = nums[0]
        list1 = []
        for i in range(n1):
            if nums[i] >= num1:
                num1 = nums[i]
            else:
                return(i-1)
                #num1 = nums[i]
        return(i)
                
```
