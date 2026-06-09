class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort() 
        def backtrack(nums, list_one):
            if not nums:
                res.append(list_one[:])#####切记 [:]
                return 
            for i in range(len(nums)):
                if i>0 and nums[i] == nums[i-1]:continue #避免重复。
                list_one.append(nums[i])
                backtrack(nums[:i] + nums[i+1:], list_one) 
                list_one.pop()
        res = []
        list_one=[]
        backtrack(nums, list_one)
        return res