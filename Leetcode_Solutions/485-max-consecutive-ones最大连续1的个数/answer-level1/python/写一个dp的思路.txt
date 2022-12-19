```
class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = [0]*len(nums)
        if nums[0]==1:
            dp[0]=1
        for i in range(1,len(nums)):
            if nums[i]==1:
                dp[i]= dp[i-1]+1
            else:
                dp[i] = 0
        return max(dp)
```
