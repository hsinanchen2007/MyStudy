dfs法：

```
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        d = {}
        def f(c, i):
            if i in d:
                return d[i] == c
            d[i] = c
            for j in graph[i]:
                if not f(not c, j):
                    return False
            return True
        for i in range(n):
            if i not in d and not f(True, i):
                return False
        return True
```

bfs法:

```
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        b = set()
        for k in range(n):
            if not graph[k] or k in b:
                continue
            c = {k: True}
            b.add(k)
            que = {k}
            res = -n
            while res<n:
                tmp = set()
                for i in que:
                    for j in graph[i]:
                        if j in c and c[j] == c[i]:
                            return False
                        c[j] = not c[i]
                        b.add(j)
                        tmp |= {j}
                        res += 1
                que = tmp
        return True
```

