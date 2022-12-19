```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        total_max = float('-inf')
        total = 0

        for num in nums:
            total = max(total + num, num)  # 子序和 只有两种情况，取最大值即可
            if total > total_max:
                total_max = total

        return total_max
```
