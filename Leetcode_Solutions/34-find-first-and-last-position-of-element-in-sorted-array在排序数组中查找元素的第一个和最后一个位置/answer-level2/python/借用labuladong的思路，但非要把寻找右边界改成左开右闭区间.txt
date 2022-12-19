### 解题思路
labuladong在寻找左右边界中都使用的是左闭右闭或者左闭右开区间，但我想，搜左边界用左闭右开，那搜右边界岂不是应该用左开右闭？结果引起舒适，试了半天才调明白

### 代码

```python3
class Solution:
    def search_left(self,nums,target):
        left,right = 0,len(nums)
        while left<right:
            mid = (left+right)//2
            if nums[mid] == target:
                right = mid
            elif nums[mid]>target:
                right = mid
            else:
                left = mid+1
        if left == len(nums) or nums[left]!=target:
            return -1
        return left

    def search_right(self,nums,target):
        import numpy as np
        left,right = -1,len(nums)-1
        while left<right:
            mid = int(np.ceil((left+right)/2))
            if nums[mid] == target:
                left = mid
            elif nums[mid]>target:
                right = mid-1
            else:
                left = mid
        if right == len(nums) or nums[right]!=target:
            return -1
        return right

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0:
            return [-1,-1]
        left_pos = self.search_left(nums,target)
        right_pos = self.search_right(nums,target)
        return [left_pos,right_pos]

```