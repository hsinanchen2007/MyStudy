### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        global_max = -float('inf')
        local_max = -float('inf')
        for i in range(len(nums)):
            local_max = max(local_max+nums[i], nums[i])
            global_max = max(local_max, global_max)
        return global_max


```