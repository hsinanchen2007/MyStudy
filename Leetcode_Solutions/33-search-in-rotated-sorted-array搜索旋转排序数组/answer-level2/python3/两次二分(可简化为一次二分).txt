第一次二分：找到最小数的位置
第二次二分：确定 target 在左侧区间还是右侧，用一个普通的二分法即可找到

其实，可以简化为一次二分

```
class Solution:
    def search(self, nums, target):
        if len(nums) == 0 or nums is None:
            return -1
        
        min_index = self.find_min(nums)
        if nums[min_index] <= target <= nums[-1]:
            return self.binarySearch(nums, min_index, len(nums)-1, target)
        return self.binarySearch(nums, 0, min_index-1, target)
    
    
    def find_min(self, nums):
        left = 0
        right = len(nums) - 1
        mid = 0 # 数组本身也是旋转数组
        
        if nums[left] <= nums[right]:
            return mid
        
        while nums[right] <= nums[left]:
            # 两个元素
            if right - left == 1:
                mid = right
                break
            mid = left + (right - left) // 2
            if nums[mid] >= nums[left]:
                left = mid
            if nums[mid] <= nums[right]:
                right = mid
        
        return mid
    
    def binarySearch(self, nums, left, right, target):
        
        if left > right:
            return -1
        
        while left <= right:
            mid = left + (right - left) // 2
            if target == nums[mid]:
                return mid
            elif target > nums[mid]:
                left = mid + 1
            else:
                right = mid - 1
                
        return -1
```
