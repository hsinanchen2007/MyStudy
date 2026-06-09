### 解题思路
动态规划。

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        s = nums[0]
        for i in range(1, len(nums)):
            nums[i] = max(nums[i], nums[i] + s)
            s = nums[i]
        return max(nums)


```