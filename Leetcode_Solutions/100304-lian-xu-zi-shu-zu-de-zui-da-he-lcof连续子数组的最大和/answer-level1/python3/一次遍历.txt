```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        cur = 0
        ans = -2147483648
        for num in nums:
            if cur < 0:
                cur = num 
            else:
                cur += num
            ans = max(cur, ans)
        return ans 
```