```
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        start = 0 
        end = len(nums) -1 
       
        while start <= end:
            mid = (start + end) //2
            if nums[mid] == mid:
                start = mid +1 
            else:
                end = mid - 1
        return start
```
