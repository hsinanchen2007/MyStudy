### 解题思路
关键点：二分查找，最左边和最右边和中间都相等的情况

### 代码

```python3
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if nums[0] < nums[-1]:
            return nums[0]
        
        l, r = 0, len(nums) - 1
        while l < r:
            m = (l + r) // 2
            if nums[l] == nums[m] == nums[r]:
                l = l + 1
                r = r - 1
            elif nums[m] <= nums[r]:
                r = m
            else:
                l = m + 1
        return nums[l]
```