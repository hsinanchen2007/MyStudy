### 解题思路
迭代版
### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        dp0,dp1=0,0
        for i in range(1,len(nums)+1):
            dp0,dp1=dp1,max(dp0+nums[i-1],dp1)  
        return dp1
```