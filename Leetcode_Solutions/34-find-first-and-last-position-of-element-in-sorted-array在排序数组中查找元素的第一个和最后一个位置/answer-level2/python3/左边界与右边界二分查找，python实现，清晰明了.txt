```python []
class Solution:  
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left_index = self.twof_left(nums,target)
        right_index = self.twof_right(nums,target)
        return [left_index,right_index]  
    
    def twof_left(self,nums,target):
        if not nums : return -1
        right = len(nums)
        left = 0
        while left < right:
            mid = (left+right)>>1
            if nums[mid] == target:
                right = mid
            elif target < nums[mid]:
                right = mid
            elif target > nums[mid]:
                left = mid+1
        if left == len(nums): return -1
        return left if nums[left] == target else -1

    def twof_right(self,nums,target):
        if not nums: return -1
        right = len(nums)    
        left = 0
        while left < right:
            mid = (left+right)>>1
            if nums[mid] == target:
                left = mid+1
            elif target < nums[mid]:
                right = mid
            elif target > nums[mid]:
                left = mid+1
        if right == 0 :return -1
        return right-1 if nums[right-1] == target else -1
```


