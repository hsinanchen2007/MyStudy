


class Solution(object):
    def findNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = 0
        for i in nums:
            b=len(str(i))
            if b % 2 == 0:
                cnt = cnt + 1
        
        return cnt
