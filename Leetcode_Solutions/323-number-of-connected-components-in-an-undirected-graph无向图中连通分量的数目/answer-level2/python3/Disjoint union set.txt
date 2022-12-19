### 解题思路
构造disjoint union set，每个连通的components都会有一个共同的root
最后数有几个root parent，就有几个连通components

### 代码

```python3
class DSU:
    def __init__(self, n):
        self.par = list(range(n))
    
    def find(self, x):
        if self.par[x] != x:
            self.par[x] = self.find(self.par[x])
        return self.par[x]
    
    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px == py:
            return False
        self.par[px] = py
        return True

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        dsu = DSU(n)
        for edge in edges:
            dsu.union(*edge)
        
        for i in range(n):
            dsu.find(i)
        
        return len(set(dsu.par))

```