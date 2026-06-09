```
class Solution(object):
    def heightChecker(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        a = sorted(heights)
        b = 0
        for i in range(len(a)):
            if a[i] != heights[i]:
                b += 1
        return b
```
