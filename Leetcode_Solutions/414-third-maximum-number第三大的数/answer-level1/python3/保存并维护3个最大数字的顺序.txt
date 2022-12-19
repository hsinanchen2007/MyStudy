```
class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return None
        mx = [float('-inf'), float('-inf'), float('-inf')]
        for n in nums:
            if n in mx:
                continue
            if n > mx[0]:
                mx = [n, mx[0], mx[1]]
            elif n > mx[1]:
                mx = [mx[0], n, mx[1]]
            elif n > mx[2]:
                mx[2] = n
        return mx[2] if mx[2]> float('-inf') else mx[0]
```
