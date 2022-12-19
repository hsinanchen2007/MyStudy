### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        '''
        #1. Dp
        for i in range(1,len(nums)):
            nums[i] = max(nums[i],nums[i]+nums[i-1])
        return max(nums)
        '''
        '''
        #2. Dp
        if len(nums)==0: return 0
        dp=[0 for _ in range(len(nums))]
        dp[0] = nums[0]
        for i in range(1,len(nums)):
            if dp[i-1]>=0:
                dp[i] = dp[i-1]+nums[i]
            else:
                dp[i] = nums[i]
        return max(dp)
        '''
        #3. left，right
        if len(nums)==1: return nums[0]
        else:
            max_left = self.maxSubArray(nums[0:len(nums)//2])
            max_right = self.maxSubArray(nums[len(nums)//2:len(nums)])
        
        max_l = nums[len(nums) // 2 - 1]
        tmp = 0
        for i in range(len(nums) // 2 - 1, -1, -1):
            tmp += nums[i]
            max_l = max(tmp, max_l)
        
        max_r = nums[len(nums) // 2]
        tmp = 0
        for i in range(len(nums) // 2, len(nums)):
            tmp += nums[i]
            max_r = max(tmp, max_r)
        
        return max(max_right,max_left,max_l+max_r)
```