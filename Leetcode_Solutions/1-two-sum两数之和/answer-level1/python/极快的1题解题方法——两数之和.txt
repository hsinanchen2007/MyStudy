详细的看博客——https://blog.csdn.net/TeFuirnever/article/details/89110423

```py
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) <= 1:
            return False
        keys = {}
        for i, v in enumerate(nums):
            if target-v in keys:
                return [keys[target-v],i]
            else:
                keys[v] = i
        return None

```
