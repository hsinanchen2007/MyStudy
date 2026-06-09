```
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left,right=0,len(nums)-1
        while right-left>1:
            mid=left+(right-left)//2
            if nums[mid]>nums[right]:
                left=mid
            else:
                right=mid
        return min(nums[left],nums[right])
```
