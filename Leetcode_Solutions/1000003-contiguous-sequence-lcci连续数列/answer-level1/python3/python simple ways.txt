### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        '''
        maxsum,sum = float('-inf'), float('-inf')
        for i in nums:
            sum = max(sum+i,i)
            maxsum = max(sum,maxsum)
        return maxsum
        '''

        
        dp = [0]*len(nums)
        if len(nums)==0: return 0
        elif len(nums)==1: return nums[0]
        else:
            dp[0] = nums[0]
            for i in range(1,len(nums)):
                dp[i] = max(nums[i],dp[i-1]+nums[i])
        return max(dp)
        
```