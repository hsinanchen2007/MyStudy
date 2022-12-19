利用二分查找两次即可，二分查找十分注重细节，利用标准的二分查找模板
```python []
ef binarySearch(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: int
    """
    if len(nums) == 0:
        return -1

    left, right = 0, len(nums)
    while left < right:
        mid = (left + right) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid

```

进行两次二分查找后
```python []
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        #最终输出[left , right]
        first, second = -1, -1
        #利用二分查找，先查找上边界
        left = 0
        right = len(nums)
        left2, right2, mid2 = 0, 0, 0
        #标志位
        i = 0
        while first == -1:
            if left >= right:
                return [-1, -1]
            mid = (right + left) // 2
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid
            else:
                i += 1
                if i == 1:
                    left2, right2, mid2 = left, right, mid
                if mid == 0 or nums[mid - 1] != target:
                    first = mid
                elif nums[mid - 1] == target:
                    right = mid
        while second == -1:
            if nums[mid2] < target:
                left2 = mid2 + 1
            elif nums[mid2] > target:
                right2 = mid2 
            else:
                if mid2 == len(nums) - 1 or nums[mid2 + 1] != target:
                    second = mid2
                elif nums[mid2 + 1] == target:
                    left2 = mid2 + 1
            mid2 = (right2 + left2) // 2
        return [first, second]
```
最终击败99%用户
