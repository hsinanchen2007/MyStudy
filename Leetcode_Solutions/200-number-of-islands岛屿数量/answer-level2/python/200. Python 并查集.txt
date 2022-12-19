### 解题思路
这道题显然是连通性问题，对于连通性问题的解决方法就是并查集，下面代码实现了一个使用路径压缩的weighted quick union算法。
一般的并查集是用来查看两个节点是否属于一个集合以及当前一共包括几个集合，由于这道题对于集合的运算不应该包括'0'，所以需要在使用并查集插入后做进一步的判断，也就是判断当前集合是否是'0’集合。

### 代码

```python
class Union_set:
    def __init__(self, n):
        self.data = [i for i in range(n)] # 记录每个节点的祖先节点
        self.size = [1] * n               # 记录每个节点的子树的节点数
        self.cnt = n                      # 记录当前的集合数量

    def find(self, m):
        """
        查找祖先（根节点）。时间复杂度接近O(1)。
        """
        if self.data[m] == m:
            return m
        ancestor = self.find(self.data[m]) # 找到祖先节点（根节点）
        self.data[m] = ancestor
        return ancestor

    def union(self, a, b):
        """
        对两个节点相连。时间复杂度接近O(1)。
        """
        ancestor_a = self.find(a)
        ancestor_b = self.find(b)
        if ancestor_a == ancestor_b:
            return 
        if self.size[ancestor_a] > self.size[ancestor_b]:
            self.data[ancestor_b] = ancestor_a
            self.size[ancestor_a] += ancestor_b
        else:
            self.data[ancestor_a] = ancestor_b
            self.size[ancestor_b] += ancestor_a
        self.cnt -= 1

class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """ 
        if grid == []:
            return 0
        len_1 = len(grid)
        len_2 = len(grid[0])
        us = Union_set(len_1 * len_2)
        for i in range(len_1):
            for j in range(len_2):
                if i > 0 and grid[i][j] == '1' and grid[i - 1][j] == '1':
                    us.union(i * len_2 + j, (i - 1) * len_2 + j)
                if j > 0 and grid[i][j] == '1' and grid[i][j - 1] == '1':
                    us.union(i * len_2 + j, i * len_2 + (j - 1))
        num = 0
        for i in range(len_1):
            for j in range(len_2):
                m = i * len_2 + j
                if us.data[m] == m and grid[i][j] == '1':
                    num += 1
        return num
```