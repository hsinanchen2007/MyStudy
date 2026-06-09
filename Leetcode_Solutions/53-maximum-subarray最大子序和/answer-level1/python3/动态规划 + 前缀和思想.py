

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = float('-inf')
        dp_min,dp_sum,pointer = 0,0,0
        while pointer < len(nums):
            dp_sum += nums[pointer]
            if dp_sum - dp_min > res:
                res = dp_sum - MIN
            if dp_sum < dp_min:
                MIN = dp_sum
            pointer += 1
        return res

            
```