### 解题思路
二分搜索找特异点即可

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        #思路：二分搜索
        n = len(nums)
        if nums[0] != 0:
            return 0
        if nums[-1] != n:
            return n
        left = 0
        right = n-1
        while left <= right:
            idx = (left + right) // 2
            if nums[idx] == idx:
                left = idx + 1
            else:
                right = idx - 1
        return left

```