### 解题思路
动态规划

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        Max=max(nums)
        dp=0
        for i in nums:
            if i+dp>0:
                dp=dp+i
                if dp>Max:
                    Max=dp    
            else:
                dp=0
        return Max
```