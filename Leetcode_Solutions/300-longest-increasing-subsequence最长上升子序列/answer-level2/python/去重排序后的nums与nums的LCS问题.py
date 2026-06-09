### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        sort_nums = sorted(list(set(nums)))
        #print(sort_nums)
        dp = [[float('-inf') for _ in range(len(sort_nums)+1)] for i in range(len(nums)+1)]
        for i in range(len(sort_nums)+1):
            dp[0][i]=0
        for i in range(len(nums)+1):
            dp[i][0]=0

        for i in range(1,len(nums)+1):
            for j in range(1,len(sort_nums)+1):
                if nums[i-1]==sort_nums[j-1]:
                    dp[i][j]=dp[i-1][j-1]+1
                else:
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1])
        #print(dp)
        return dp[-1][-1]
         
```