### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        spe = max(nums)
        if spe < 0:
            return spe 
        
        local_max, global_max = 0, float('-inf')
        
        for num in nums:
            local_max = max(0, local_max + num)
            global_max = max(global_max, local_max)
        
        return global_max

```