class Solution(object):
    def massage(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        if n==0:
            return 0
        dp=[0]*n
        dp[0]=nums[0]
        if n==1:
            return dp[0]
        dp[1]=max(nums[0],nums[1])
        for i in range(2,n):
            dp[i]=max(dp[i-2]+nums[i],dp[i-1])
        return dp[n-1]
            