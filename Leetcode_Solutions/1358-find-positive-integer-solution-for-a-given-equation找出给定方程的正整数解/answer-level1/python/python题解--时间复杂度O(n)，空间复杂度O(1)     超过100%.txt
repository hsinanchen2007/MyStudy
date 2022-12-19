```
class Solution(object):
    def findSolution(self, customfunction, z):
        """
        :type num: int
        :type z: int
        :rtype: List[List[int]]
        """
        x = 1
        y = 1000
        result = []
        while x <= 1000 and y >= 1:
            
            if customfunction.f(x, y) == z:
                result.append([x,y])
                x += 1
                y -= 1
            elif customfunction.f(x, y) > z:
                y -= 1
            else:
                x += 1
        return result
```
