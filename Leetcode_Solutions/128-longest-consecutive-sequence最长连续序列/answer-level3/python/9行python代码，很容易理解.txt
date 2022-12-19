对于每一个数，判断其后续连续数字是否在数组中

python中set()查询复杂度为O(1)

```
class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = set(nums)
        res = 0
        for x in nums:
            if x-1 not in nums:
                y = x + 1
                while y in nums:
                    y += 1
                res = max(res,y-x)
        return res
```
