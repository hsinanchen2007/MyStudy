### 解题思路
这题真的是简单难度吗...卡了好久只有暴力求解的思路
从前向后遍历，求得每一个位置的最优和，
而且用max()比 ">"判断要快一些，学到了...

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxsum = nums[0]
        for i in range(1, len(nums)):
            nums[i] = max(nums[i], nums[i] + nums[i - 1])
            maxsum = max(nums[i], maxsum)
        return maxsum
```