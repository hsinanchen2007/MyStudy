
```python []
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length == 0: #1)注意处理空数组
            return 0
        dp = [0]*length #2） python list 初始化方式
        result = 0
        for i in xrange(length):
            dp[i] = 1 #dp[i] means  LIS length which ends with nums[i]
            for j in xrange(0,i):
                if( nums[i] > nums[j] and dp[j]+1 > dp[i] ): #3）注意python 没有&& ，要用and
                    dp[i] = dp[j]+1
            result = max(result,dp[i]) #4）注意要在dp[i]里选max值
            
        return result
```

