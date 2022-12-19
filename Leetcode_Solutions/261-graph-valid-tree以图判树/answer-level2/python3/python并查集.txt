判断条件：

1.并查集中只有一个root：说明图连通。
2.边的个数为节点个数-1，否则存在环。

```python
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n - 1:
            return False

        class UF:
            def __init__(self, n):
                self.rank = [0 for _ in range(n)]
                self.up = [i for i in range(n)]
            
            def find(self, x):
                if self.up[x] == x:
                    return x
                else:
                    self.up[x] = self.find(self.up[x])
                    return self.up[x]

            def union(self, x1, x2):
                r1 = self.find(x1)
                r2 = self.find(x2)
                if r1 == r2:
                    return
                if self.rank[r1] == self.rank[r2]:
                    self.rank[r1] += 1
                    self.up[r2] = r1
                elif self.rank[r1] > self.rank[r2]:
                    self.up[r2] = r1
                else:
                    self.up[r1] = r2

        uf = UF(n)
        for v1, v2 in edges:
            uf.union(v1, v2)

        count = 0
        for i in range(n):
            if uf.find(i) == i:
                count += 1

        return count == 1
```