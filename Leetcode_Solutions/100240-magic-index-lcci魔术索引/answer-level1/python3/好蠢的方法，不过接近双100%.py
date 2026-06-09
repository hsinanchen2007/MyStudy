class Solution:
    def findMagicIndex(self, nums: List[int]) -> int:
        res=9999999999
        if not len(nums):return -1
        for i,j in enumerate(nums):
            if i ==j:
                res=min(res,i)
        if res==9999999999:
            return -1
        else:
            return res