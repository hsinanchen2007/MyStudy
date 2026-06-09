```python
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        if nums == []: return False
        # 先找到分界点
        left, right = 0, len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] >= nums[0]:
                left += 1
            else:
                right = mid
        if nums[-1] > nums[0]: left = 0
        while left != 0 and nums[left] == nums[left - 1]: left -= 1
        # 然后根据二分查找查找目标值
        if target == nums[left]:return True
        elif target > nums[-1]:
            index = bisect.bisect(nums[:left], target) - 1
        else:
            index = left + bisect.bisect(nums[left + 1:], target)
        return nums[index] == target
```
