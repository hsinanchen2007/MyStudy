```python
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        # Topo Sort
        # Time complexity : O(N)
        # Space complexity: O(N ** 2)
        n = max([max(a, b) for a, b in edges])
        in_degree = [0] * (n + 1)
        adj = collections.defaultdict(list)
        for a, b in edges:
            in_degree[a] += 1
            in_degree[b] += 1
            adj[a].append(b)
            adj[b].append(a)

        queue = []
        visited = set()
        for i in range(1, n + 1):
            if in_degree[i] == 1:
                queue.append(i)
                visited.add(i)
        
        while queue:
            top = queue.pop()
            visited.add(top)
            for nei in adj[top]:
                if nei not in visited:
                    in_degree[nei] -= 1
                    if in_degree[nei] == 1: queue.append(nei)

        for a, b in reversed(edges):
            if a in visited or b in visited: continue
            return [a, b]
```