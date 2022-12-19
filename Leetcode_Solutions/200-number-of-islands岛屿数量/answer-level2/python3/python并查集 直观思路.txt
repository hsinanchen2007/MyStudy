并查集python实现，使用路径压缩和rank合并。
给想用py实现并查集的同学提供个思路吧

```
from typing import List

class UnionFind:
    def __init__(self, n):
        self.count = n
        self.parent = [i for i in range(n)]
        self.rank = [1 for _ in range(n)] #记录每个结点的深度，方便合并时优化
    
    def get_count(self):
        return self.count
    
    def find(self, x):
        if self.parent[x] == x:
            return x
        boss = self.find(self.parent[x]) #找到根结点
        #路径压缩
        self.parent[x] = boss
        return boss

    def is_one(self, p, q):
        return self.find(p) == self.find(q)

    def union(self, p, q):
        p_root = self.find(p)
        q_root = self.find(q)
        if p_root == q_root:
            return
        #在合并时，将rank小的合并到rank大的上去，这样可以提升查找效率
        if self.rank[p_root] > self.rank[q_root]:
            self.parent[q_root] = p_root
        elif self.rank[p_root] < self.rank[q_root]:
            self.parent[p_root] = q_root
        else:
            self.parent[q_root] = p_root
            self.rank[p_root] += 1
        #每一次合并，总的集合数就会-1
        self.count -= 1

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:

        if not grid or not grid[0]: return 0
        row = len(grid)
        col = len(grid[0])
        #上和左
        d = [(-1, 0), (0, -1)]
        def get_index(x, y):
            return x * col + y
        uf = UnionFind(row * col)
        for i in range(row):
            for j in range(col):
                if grid[i][j] == '0':
                    uf.count -= 1
                #grid[i][j] == 1
                else:
                    #判断左边和上边是否为1，为1则合并
                    for dx, dy in d:
                        x_new, y_new = i + dx, j + dy
                        if 0 <= x_new < row and 0 <= y_new <col and grid[x_new][y_new] == '1':
                            uf.union(get_index(i, j), get_index(x_new, y_new))
        return uf.get_count()
```
