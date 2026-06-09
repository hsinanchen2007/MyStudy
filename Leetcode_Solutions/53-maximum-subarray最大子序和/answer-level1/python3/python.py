```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = float('-inf')
        temp_sum = 0
        for num in nums:
            temp_sum = max(temp_sum + num, num)
            ans = max(ans, temp_sum)
        return ans
```