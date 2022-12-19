### 解题思路
动态规划，如果每次新的值，对之前的结果有贡献则用新的值，如果比当前值还小就更新为当前值

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        result = [0] * len(nums)

        result[0] = nums[0]
        for idx in range(1, len(nums)):
            result[idx] = max(result[idx - 1] + nums[idx], nums[idx])
        print(result)
        return max(result)
```