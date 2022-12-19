### 解题思路
运用二分法即可解决问题，但是要注意的一点是，如果没有发现匹配的目标，要判断当前中点的位置值是否比目标要小，若要比目标小，那么插入位置后移。

### 代码

```python3
class Solution:
    def searchInsert(self, nums: list, target: int) -> int:
        low,high = 0,len(nums)-1
        mid = (low + high) // 2
        while low <= high:
            if nums[mid] > target:
                high = mid - 1
            elif nums[mid] < target:
                low = mid + 1
            else:
                return mid
            mid = (low + high) // 2
        if mid == -1:
            return 0
        if nums[mid] > target:
            return mid
        else:
            return mid + 1
```