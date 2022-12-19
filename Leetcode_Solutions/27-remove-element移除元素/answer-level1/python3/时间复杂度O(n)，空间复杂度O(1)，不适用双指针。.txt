class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i = 0
        while nums:
            if i < len(nums):
                if nums[i] == val:
                    nums.remove(val)
                else:
                    i+=1
            else:
                break
        return (len(nums))