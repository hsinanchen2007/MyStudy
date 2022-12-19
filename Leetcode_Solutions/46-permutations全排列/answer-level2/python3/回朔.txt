
```
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        r = []
        def func(nums):
            for i in nums:
                b = nums[:]
                b.remove(i)
                r.append(i)
                if not b:
                    res.append(r[:])
                    # print(self.res)
                func(b)
                r.pop()
        func(nums)
        return res
```
