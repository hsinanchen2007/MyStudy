标准的滑窗算法，[i,j)区间标记，i向右移动，总和变小，j向右移动总和变大
```python
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        i, j = 0, 0
        sum = 0
        res = len(nums) + 1
        while i < len(nums):
            if j < len(nums) and sum < s:
                sum += nums[j]
                j += 1
            else:
                sum -= nums[i]
                i += 1
            if sum >= s:
                if j - i < res:
                    res = j - i
        if res == len(nums) + 1:
            return 0
        return res
```
