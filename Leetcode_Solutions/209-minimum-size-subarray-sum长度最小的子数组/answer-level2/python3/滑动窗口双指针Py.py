### 解题思路
此处撰写解题思路

### 代码

```python3
import sys
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        # 双指针滑动窗口O(N)
        n = len(nums)
        left = 0
        res = sys.maxsize
        preSum = 0
        if nums is None or len(nums) < 1:
            return 0
        for right in range(n):
            preSum += nums[right]
            # 左指针移动
            while preSum >= s:
                res = min(right - left + 1, res)
                preSum -= nums[left]
                left += 1
        return res if res != sys.maxsize else 0
```