### 解题思路
此处撰写解题思路
 # label[i] 表示第i个元素的最大递增序列有多少种
 # dp[i]表示第i个元素最大递增序列的长度
 #nums[i]>nums[j] and dp[i]=dp[j]+1
### 代码

```python3
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        n=len(nums)
        dp=[1]*n
        label=[1]*n
        for i in range(1,n):
            for j in range(i):
                if nums[j]<nums[i]:
                     if dp[i]<dp[j]+1:
                        dp[i]=dp[j]+1
                        label[i]=label[j]
                     elif dp[i]==dp[j]+1:
                        label[i]+=label[j]
        print(dp)  
        print(label)                
        ans=0
        maxs=max(dp)
        for i in range(n):
            if dp[i]==maxs:
               ans+=label[i]
        return ans
```