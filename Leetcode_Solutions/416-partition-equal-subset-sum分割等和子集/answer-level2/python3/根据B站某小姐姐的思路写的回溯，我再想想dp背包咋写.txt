### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        numsum = sum(nums)
        if numsum % 2 != 0:
            return False
        def backtrack(nums, i, target):
            if target == 0:
                return True
            if target < 0 or i >= len(nums):
                return False
            if backtrack(nums, i+1, target-nums[i]):
                return True
            j = i + 1
            while j < len(nums) and nums[i] == nums[j]:
                j += 1
            return backtrack(nums, j, target)
        return backtrack(nums, 0, numsum/2)
```