### 解题思路
二分查找的思想，这位大佬[@labuladong](/u/labuladong/)已经讲得很细致了，个人觉得比官方题解好太多，我按照大佬的思想，用Python实现了，运行时间37ms，超过97%的用户，供参考。

### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l = self.leftboundSearch(nums, target)
        r = self.rightboundSearch(nums, target)
        return [l, r]

    def leftboundSearch(self, nums, target):
        if len(nums) == 0:
            return -1
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                right = mid - 1
            elif nums[mid] > target:
                right = mid - 1
            elif nums[mid] < target:
                left = mid + 1
        if left == len(nums) or nums[left] != target:
            return -1
        return left

    def rightboundSearch(self, nums, target):
        if len(nums) == 0:
            return -1
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            elif nums[mid] < target:
                left = mid + 1
        if right < 0 or nums[right] != target:
            return -1
        return right


```