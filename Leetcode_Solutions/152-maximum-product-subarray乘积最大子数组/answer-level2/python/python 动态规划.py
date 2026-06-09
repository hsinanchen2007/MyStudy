### 解题思路
注意动态规划中dp[i]表示的是以**nums[i]结尾的数组**中乘积最大的，而不是**前i个数中**连续乘积最大的。故最后返回max(dpmax)，而非dpmax[-1]

### 代码

```python3
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        dpmin = [0 for _ in nums]
        dpmax = [0 for _ in nums]
        dpmin[0] = nums[0]
        dpmax[0] = nums[0]
        for i in range(1,len(nums)):
            if nums[i]>=0:
                dpmax[i] = max(dpmax[i-1]*nums[i],nums[i])
                dpmin[i] = min(dpmin[i-1]*nums[i],nums[i])
            else:
                dpmax[i] = max(dpmin[i-1]*nums[i],nums[i])
                dpmin[i] = min(dpmax[i-1]*nums[i],nums[i])
        return max(dpmax)
```