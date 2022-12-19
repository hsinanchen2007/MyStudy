典型的并查集思路，为成团的构建公共father
```
class Solution(object):
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        def findfa(x):
            while x != father[x]:
                x = father[x]
            return x
            
        father = {}
        for u, v in edges:
            if u not in father:
                father[u] = u
            if v not in father:
                father[v] = v
            pu, pv = findfa(u), findfa(v)
            if pu == pv:
                return [u, v]
            father[pu] = pv
```

