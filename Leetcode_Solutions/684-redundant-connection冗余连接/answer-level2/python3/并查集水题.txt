由于题目已经保证了只有一个桥，那么直接做并差集来判断连通性就好了。遇到第一个联通节点直接输出。

```python
class Solution:
    def __init__(self):
        self.par = [i for i in range(1005)]
        self.rank = [0 for _ in range(1005)]
        
    def find(self, x) -> int:
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]
        
    def uniq(self, p: int, q: int):
        p, q = self.find(p), self.find(q)
        if p == q:
            return
        else:
            self.par[q] = p
            if self.rank[p] == self.rank[q]:
                self.rank[p] += 1
        
        
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        for e in edges:
            x, y = e[0], e[1]
            if self.find(x) == self.find(y):
                return [x, y]
            else:
                self.uniq(x, y)
        return []        
        
```