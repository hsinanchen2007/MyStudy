class Solution(object):
    def searchInsert(self, nums, target):
        if target not in nums:
            nums.append(target)
            nums.sort()
            return nums.index(target)                
        else:
            return nums.index(target)