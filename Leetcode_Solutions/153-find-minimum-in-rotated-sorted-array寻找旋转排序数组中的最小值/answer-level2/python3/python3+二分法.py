### 解题思路
采用二分法即可，有点类式于之前的一道题
![2019-12-05 22-57-38屏幕截图.png](https://pic.leetcode-cn.com/6ffb68067f947293389f5d5aa720b3b49e19f67ea6c5c161d36a38da01f07355-2019-12-05%2022-57-38%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

### 代码

```python3
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        left = 0
        right = len(nums)-1
        while left < right:
            if nums[right] > nums[left]:
                return nums[0]
            mid = left + (right - left + 1) // 2
            if nums[mid] < nums[left]:
                right = mid
                if nums[mid] < nums[mid-1] and (mid == len(nums)-1 or nums[mid] < nums[mid+1]):
                    return nums[mid]
            else:
                left = mid
                if nums[mid] < nums[mid-1] and nums[mid] < nums[mid+1]:
                    return nums[mid]
```