### 解题思路
先用递归写出表达式
然后自底向上计算, 减少重复运算.

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        # def steal(nums, i):
        #     if i == 0:
        #         return nums[0]
        #     if i == 1:
        #         return nums[1]
        #     return max(steal(nums, i - 1), steal(nums, i - 2) + nums[i])
        
        # return steal(nums, len(nums) - 1)

        if len(nums) == 0: return 0
        if len(nums) <= 2: return max(nums)
        A = [0] * len(nums)
        A[0] = nums[0]
        A[1] = max(nums[1], nums[0])
        for i in range(2, len(nums)):
            A[i] = max(A[i-1], A[i-2] + nums[i])
        return A[-1]


```