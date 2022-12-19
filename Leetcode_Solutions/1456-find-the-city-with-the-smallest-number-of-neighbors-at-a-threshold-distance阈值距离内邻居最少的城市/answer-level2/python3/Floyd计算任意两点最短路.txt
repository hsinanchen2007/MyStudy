```python []
class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        import copy
        M = 1e4+10
        edge = [[M for i in range(n)] for j in range(n)]
        for e in edges:
            edge[e[0]][e[1]] = edge[e[1]][e[0]] = e[2]
        for i in range(n):
            edge[i][i] = 0
        A = copy.deepcopy(edge)
        path = [[0 for i in range(n)] for j in range(n)]
        
        def Floyd():
            for i in range(n):
                for j in range(n):
                    if(edge[i][j] != M and edge[i][j] != 0):
                        path[i][j] = i

            for a in range(n):
                for b in range(n):
                    for c in range(n):
                        if A[b][a]+A[a][c]<A[b][c]:
                            A[b][c] = A[b][a] + A[a][c]
                            path[b][c] = path[a][c]

        Floyd()
        print(A)
        print(edge)
        stash = [0 for i in range(n)]
        for i in range(n):
            cnt = 0
            for j in range(n):
                if A[i][j] <= distanceThreshold and i != j:
                    cnt += 1
            stash[i] = cnt
        print(stash)
        minvalue = min(stash)
        for i in range(n-1,-1,-1):
            if stash[i] == minvalue:
                return i
```

