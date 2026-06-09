```
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if len(nums) ==1:
            return 0
        if len(nums) == 2:
            return nums.index(max(nums))
        left,right=0,len(nums)-1
        while left+1<right:
            mid = (left+right)//2
            if nums[mid-1]<nums[mid] and nums[mid+1]<nums[mid]:
                return mid
            elif nums[mid] < nums[mid-1]:
                right = mid
            elif nums[mid] < nums[mid+1]:
                left=mid
        if left == 0:
            return left
        elif nums[left] > nums[left-1] and nums[left] >nums[left+1]:
            return left
        if right == len(nums)-1:
            return right
        elif nums[right] > nums[right-1] and nums[right] >nums[right+1]:
            return right
```
