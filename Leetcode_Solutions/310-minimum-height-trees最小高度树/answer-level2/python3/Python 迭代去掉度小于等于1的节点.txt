
```
from collections import defaultdict
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
        
        # 邻接表
        adj = defaultdict(set) 
        for i, j in edges:
            adj[i].add(j)
            adj[j].add(i)
        
        # 去掉度小于等于1的节点
        while len(adj) > 2:    
            vs = [k for k, ns in adj.items() if len(ns) <= 1]
            for v in vs:
                if adj[v]:
                    adj[adj[v].pop()].remove(v)
                del adj[v]
        return list(adj)
        
        
        
```
