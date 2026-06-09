### 解题思路
此处撰写解题思路
dp[i]=max(nums[i],nums[i]+dp[i-1])
### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        len_nums=len(nums)
        dp=[0 for i in range(len_nums)]
        dp[0]=nums[0]
        if len_nums==1:
            return dp[0]
        for i in range(1,len_nums):
            dp[i]=max(nums[i],nums[i]+dp[i-1])
        return max(dp)

```