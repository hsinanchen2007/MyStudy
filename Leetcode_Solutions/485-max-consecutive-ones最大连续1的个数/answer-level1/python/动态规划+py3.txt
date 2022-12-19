### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        n=len(nums)
        if n<0 or not nums:
            return 0
        dp=[0]*n
        if nums[0]==1:
            dp[0]=1
        for i in range(1,n):
            if nums[i-1]==1 and nums[i]==1:
                dp[i]=dp[i-1]+1
            elif nums[i-1]==0 and nums[i]==1:
                dp[i]=1
        return max(dp)
                 

```