### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n=len(nums)
        if not nums or n<0:
            return 0
        dp=[1]*(n+1)
        for i in range(1,n):
            for j in range(i):
                if nums[i]>nums[j]:
                    #要更新和自己比 比如[1,2,6,4,10]
                    dp[i]=max(dp[i],dp[j]+1)
        return max(dp)
```