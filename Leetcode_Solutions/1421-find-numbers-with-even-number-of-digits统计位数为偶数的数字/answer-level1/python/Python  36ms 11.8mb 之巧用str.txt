简单易懂！这读不懂我也没啥办法了


class Solution(object):
    def findNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count=0
        for num in nums:
            if len(str(num)) %2==0:
                count+=1
        return count