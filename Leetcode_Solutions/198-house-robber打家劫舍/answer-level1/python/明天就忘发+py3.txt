### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        if not nums or n<0:
            return 0
        if n<3:
            return max(nums)
        dp=[0]*n
        dp[0]=nums[0]
        dp[1]=nums[1]
        for  i in range(2,n):
            for j in range(i-1):
                dp[i]=max(dp[i],dp[j]+nums[i])
        return  max(dp)
```