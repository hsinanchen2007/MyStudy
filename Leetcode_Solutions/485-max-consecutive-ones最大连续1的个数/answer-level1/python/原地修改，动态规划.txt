### 解题思路

### 代码

```python3
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        for i in range(1, len(nums)):
            if nums[i] == 1:
                nums[i] = 1 + nums[i-1]
        return max(nums)
```