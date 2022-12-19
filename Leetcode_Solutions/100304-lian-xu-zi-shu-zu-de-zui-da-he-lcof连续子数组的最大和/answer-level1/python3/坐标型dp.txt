### 解题思路
 
设dp[i]代表以元素nums[i]结尾连续数组最大和
### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        dp=[0]*len(nums)
        dp[0]=nums[0]
        for i in range(1,len(nums)):
            dp[i]=max(nums[i],nums[i]+dp[i-1])
        return max(dp)
```