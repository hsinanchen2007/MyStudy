### 代码

```python3
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        i = 0
        while i+1 < len(nums):
            ans += nums[i]
            i += 2
        return ans
```