```python
class Solution:
    def leadsToDestination(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        adj = collections.defaultdict(list)
        for a, b in edges:
            adj[a].append(b)
        flag = True
        if destination in adj[destination]: return False
        visited = set()
        
        def dfs(node, visited):
            nonlocal flag
            visited.add(node)
            if len(adj[node]) == 0 and node != destination:
                flag = False
                return
            for neibor in adj[node]:
                if neibor in visited:
                    flag = False
                    return
                dfs(neibor, visited)
            visited.remove(node)
        dfs(source, visited)
        return flag
```