```
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n - 1:
            return False
        p = [i for i in range(n)]
        r = [0] * n

        def find(u):
            if p[u] != u:
                p[u] = find(p[u])
            return p[u]

        def union(u, v):
            u, v = find(u), find(v)
            if r[u] > r[v]:
                p[v] = u
            else:
                p[u] = v
                if r[u] == r[v]:
                    r[v] += 1

        for u, v in edges:
            union(u, v)

        for u in range(n):
            find(u)

        return len(set(p)) == 1
```
