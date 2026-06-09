class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        #保留最后一位来计算sumRange(0, j)的情况
        self.sum = [0]*(len(nums)+1)
        if nums:
            self.sum[0] = nums[0]
            for i in range(1, len(nums)):
                self.sum[i] = self.sum[i-1]+nums[i]

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.sum[j] - self.sum[i-1] if self.sum else 0