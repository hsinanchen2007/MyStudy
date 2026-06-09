### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # if not nums or len(nums)<=0:
        #     return 
        # n=len(nums)
        # maxSum=nums[0]
        # thisSum=0
        # for i in range(n):
        #     if thisSum>0:
        #         thisSum+=nums[i]
        #     else:
        #         thisSum=nums[i]
        #     if thisSum>maxSum:
        #         maxSum=thisSum
        # return maxSum
        n=len(nums)
        dp=[0]*(n+1)
        dp[0]=nums[0]
        maxs=nums[0]
        for i in range(1,n):
            dp[i]=max(dp[i-1]+nums[i],nums[i])
            maxs=max(dp[i],maxs)
        return maxs
```