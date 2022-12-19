```
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        import itertools
        rs=[]
        for i in itertools.permutations(nums,nums.__len__()):
            rs.append(i)
        return rs
```
