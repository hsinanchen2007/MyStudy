### 解题思路
自己看吧

### 代码

```python3
import bisect
class Solution:
    def reversePairs(self, nums) -> int:
        next_nums = list(nums)
        next_nums.sort()
        ans = 0
        for num in nums:
            idx = bisect.bisect_left(next_nums, num)
            ans += idx
            next_nums.pop(idx)
        return ans
```