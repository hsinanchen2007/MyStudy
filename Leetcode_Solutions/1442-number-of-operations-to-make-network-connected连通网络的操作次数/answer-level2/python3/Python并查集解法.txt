### 解题思路

失败：若 连线数 < 节点数 - 1，则失败。
否则必然可行。通过并查集找到独立子集的个数count，需要的连线为count-1。

### 代码

```python3
class UnionFind:
    def __init__(self, n):
        self.up = list(range(n))
        self.rank = [0 for _ in range(n)]
    
    def find(self, x):
        if self.up[x] == x:
            return x
        else:
            self.up[x] = self.find(self.up[x])
            return self.up[x]

    def union(self, x, y):
        repr_x = self.find(x)
        repr_y = self.find(y)

        if repr_x == repr_y:
            return False

        if self.rank[repr_x] == self.rank[repr_y]:
            self.rank[repr_x] += 1
            self.up[repr_y] = repr_x
        elif self.rank[repr_x] < self.rank[repr_y]:
            self.up[repr_x] = repr_y
        else:
            self.up[repr_y] = repr_x

        return True

class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n - 1: 
            return -1
        uf = UnionFind(n)
        for s, e in connections:
            uf.union(s, e)
        count = 0
        for i in range(n):
            if uf.find(i) == i:
                count += 1
        return count - 1



```