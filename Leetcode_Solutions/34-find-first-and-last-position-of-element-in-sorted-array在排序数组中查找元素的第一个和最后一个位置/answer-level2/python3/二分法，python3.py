方法一：用bisect包，思路很简单
```
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left=bisect.bisect_left(nums,target)
        right=bisect.bisect_right(nums,target)

        if left==right:
            return [-1,-1]
        return [left,right-1]
```
方法二，手动找左右边界
```
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return [-1,-1]

        left,right=0,len(nums)-1
        #寻找左边界
        while left<right:
            mid=(left+right)//2
            if nums[mid]>=target:
                right=mid
            else:
                left=mid+1

        if not nums[left]==target:
            return [-1,-1]

        #寻找右边界
        L=left
        right=len(nums)-1

        while left<right:
            mid=(left+right+1)//2
            if nums[mid]>target:
                right=mid-1
            else:
                left=mid
        return [L,right]
```
