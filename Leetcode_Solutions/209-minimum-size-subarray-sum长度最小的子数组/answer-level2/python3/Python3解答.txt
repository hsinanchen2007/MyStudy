### 解题思路
简单的双指针思路

### 代码

```python3
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        l, r, tmp = 0, 0, 0
        min_len = -1
        while r < len(nums):
            tmp += nums[r]
            if tmp >= s:
                if min_len == -1 or r - l + 1 < min_len:
                    min_len = r - l + 1
                tmp -= (nums[l] + nums[r])
                l += 1
            else:
                r += 1
        return min_len if min_len != -1 else 0
```