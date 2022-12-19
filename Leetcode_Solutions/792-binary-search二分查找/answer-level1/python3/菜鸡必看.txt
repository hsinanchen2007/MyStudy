为了递归强行递归 锻炼一下自己递归手法吧
```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def helper(nums,left,right,target) :
            mid = (left+right) // 2
            if nums[mid] == target :
                return mid
            elif nums[mid] < target :
                return helper(nums,mid+1,right,target)
            else :
                return helper(nums,left,mid-1,target)
        return helper(nums,0,len(nums)-1,target)
```
