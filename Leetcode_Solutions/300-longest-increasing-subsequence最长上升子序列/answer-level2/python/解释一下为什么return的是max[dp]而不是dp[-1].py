### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        n=len(nums)
        dp = [1]*n
        res = 1
        for i in range(n):
            for j in range(i):
                if nums[j]<nums[i]:
                    dp[i] = max(dp[i],dp[j]+1)
                    res = max(res,dp[i])
        return res###返回max(dp)而不是dp[-1]
###因为当前面的最长子序列[1,3,6,7,9,10]的最大值10比nums[-1]=6大的时候，就不会有dp[-1]是最大的
###实际上dp[-1]此时是[1,3,4,5,6]的长度
```