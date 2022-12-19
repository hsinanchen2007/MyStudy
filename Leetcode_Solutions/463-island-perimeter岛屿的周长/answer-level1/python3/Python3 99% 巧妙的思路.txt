### 思路：只从水平方向或者竖直方向对一个list进行观察时，相邻的岛屿实际上等价于一个。
分成水平和竖直两个方向分别对这个矩阵进行计算，检查是否为独立岛屿，若是则计数器加一；最终返回计数器的两倍即可。
```python3
class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        res = 0
        for x in grid:
            for y in range(len(x) - 1):
                if x[y]:
                    if not x[y + 1]:
                        res += 1
            if x[-1]:
                res += 1
        for x in zip(*grid):
            for y in range(len(x) - 1):
                if x[y]:
                    if not x[y + 1]:
                        res += 1
            if x[-1]:
                res += 1
        return res * 2
                
```