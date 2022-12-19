### 解题思路
染色+DFS

### 代码

```python3
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        V = len(graph)
        visited = [False] * V
        colors = [-1] * V
        def helper(v,color):
            visited[v] = True
            colors[v] = color
            for item in graph[v]:
                if not visited[item]:
                    if not helper(item,1-color):
                        return False
                elif colors[item] == colors[v]:
                    return False
            return True

        for i in range(V):
            if not visited[i]:
                if not helper(i,0):
                    return False
        return True
```