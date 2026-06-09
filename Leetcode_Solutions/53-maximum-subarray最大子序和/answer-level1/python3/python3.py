### 解题思路
利用列表max函数特性解法

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:

        for i in range(1,len(nums)):

            nums[i] = max(nums[i],nums[i]+nums[i-1])

        return max(nums)

```