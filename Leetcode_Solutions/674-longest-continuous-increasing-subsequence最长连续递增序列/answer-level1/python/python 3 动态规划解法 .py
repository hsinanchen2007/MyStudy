### 解题思路
dp[i]：表示第i个元素，它的递增元素的个数。比如[1，3，5 ]元素3 从1递增到3 递增元素个数是2,dp[1]=2
初始化 dp=[1]*n
后比较

### 代码

```python3
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        n=len(nums)
        if not nums or n<0:
            return 0
        dp=[1]*n
        for i in range(1,n):
            if nums[i]>nums[i-1]:
               dp[i]=dp[i-1]+1
        return max(dp)
```