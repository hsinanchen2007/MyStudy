class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l=len(nums)
        if l==0 or l==1:
            return l
        flag=0
        for i in range(1,l):
            i-=flag
            if nums[i]==nums[i-1]:
                nums.pop(i)
                flag+=1
        return len(nums)