### 解题思路
所有和连通性有关的问题，首先应该想到使用并查集来解决。

### 代码

```python
class UnionSet():
    def __init__(self, num):
        self.data = [i for i in range(num)]
        self.size = [1] * num
        self.num = num

    def find(self, x):
        if self.data[x] == x:
            return x
        ancestor = self.find(self.data[x])
        self.data[x] = ancestor
        return ancestor

    def union(self, x, y):
        ancestor_x = self.find(x)
        ancestor_y = self.find(y)
        if ancestor_x == ancestor_y:
            return 
        if self.size[ancestor_x] < self.size[ancestor_y]:
            self.data[ancestor_x] = ancestor_y
            self.size[ancestor_y] += self.size[ancestor_x]
        else:
            self.data[ancestor_y] = ancestor_x
            self.size[ancestor_x] += self.size[ancestor_y]
        self.num -= 1


class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        if m == 0:
            return 0
        us = UnionSet(m * n)
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    continue
                if i - 1 >= 0 and grid[i - 1][j]:
                    us.union(i * n + j, (i - 1) * n + j)
                if j - 1 >= 0 and grid[i][j - 1]:
                    us.union(i * n + j, i * n + (j - 1))
        res = 0
        for i in range(m):
            for j in range(n):
                ind = i * n + j
                if grid[i][j] and us.data[ind] == ind and us.size[ind] > res:
                    res = us.size[ind]
        return res
```