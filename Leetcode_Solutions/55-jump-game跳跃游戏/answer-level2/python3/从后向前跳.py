class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        p=len(nums)-1
        for i in range(len(nums)-2,-1,-1):
            if nums[i]>=p-i:
                p=i
        return p==0