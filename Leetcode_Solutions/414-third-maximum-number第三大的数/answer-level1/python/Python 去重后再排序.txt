class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        Only_sorted=list(sorted(set(nums)))
        if len(Only_sorted)<3:
            return Only_sorted[-1]
        else:
             return Only_sorted[-3]
            