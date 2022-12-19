class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        path = []
        def helper(nums,path):
            if len(path) == len(nums):
                res.append(path[:])
                return
            for i in nums:
                if i in path:
                    continue
                path.append(i)
                helper(nums,path)
                path.pop()
        helper(nums,path)
        return res