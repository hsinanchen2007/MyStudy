```
class Solution(object):
    def projectionArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        raw = []
        colum = []
        zero = []
        temp = -1
        for i in grid:
            zero.append(i.count(0))
            raw.append(max(i))
        for j in range(len(grid)):
            for i in grid:
                if i[j] > temp:
                    temp = i[j]
            colum.append(temp)
            temp = -1
        m = len(grid)
        result = pow(m,2)-sum(zero) + sum(colum) + sum(raw)

        return result
```
