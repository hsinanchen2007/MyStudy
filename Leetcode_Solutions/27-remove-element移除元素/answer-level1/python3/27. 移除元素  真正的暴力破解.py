class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        nums.sort()
        for i in nums:
            if val in nums:
                nums.remove(val)
            else:
                break
        if nums==[]:
            return 0
            
        if nums[0] ==val :
            
            return 0
        if len(nums)==2 and nums[1]==val:
            del nums[1]
            return int(len(nums))
        else:
            return int(len(nums))