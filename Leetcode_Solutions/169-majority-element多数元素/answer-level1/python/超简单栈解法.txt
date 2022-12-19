```
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = []
        if not nums:
            return None
        for num in nums:
            if len(res) == 0 or res[-1] == num:
                res.append(num)
            else:
                res.pop()
        return res[0]
```
