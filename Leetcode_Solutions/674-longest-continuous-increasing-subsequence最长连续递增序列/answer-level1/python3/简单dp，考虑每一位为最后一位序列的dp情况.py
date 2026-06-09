```
class Solution(object):
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums==[]:
            return 0
        rs=1
        dp=[1]*nums.__len__()
        
        for i in range(1,nums.__len__()):
            if nums[i]>nums[i-1]:
                dp[i]=dp[i-1]+1
                rs=max(rs,dp[i])
        
        return rs
```