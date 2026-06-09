我的方法是用两个 二分查找
第一个二分查找是找临界点，把排序数组分为两部分
第二个二分查找是在两个排序数组中找target
```python []
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if nums is None or len(nums)==0:
            return -1
        
        start = 0
        end = len(nums) - 1
        while start + 1 < end:
            mid = start + (end - start) // 2
            if nums[mid] < nums[end]:
                end = mid
            else:
                start = mid

        # while循环结束之后，以nums[end]为分界点
        pol = end
        result = self.binary_search(nums[:pol], target)  #在左边查找target
        if result == -1:
            result = self.binary_search(nums[pol:], target)   #在右边查找target
            if result != -1:
                result = result + len(nums[:pol])
        return result
        
    def binary_search(self, nums, target):
        if nums is None or len(nums) == 0:
            return -1
        start = 0
        end = len(nums) - 1
        while start + 1 < end:
            mid = start + (end - start) // 2
            if nums[mid] < target:
                start = mid
            elif nums[mid] > target:
                end = mid
            elif nums[mid] == target:
                return mid
        if nums[start] == target:
            return start
        if nums[end] == target:
            return end
        return -1
