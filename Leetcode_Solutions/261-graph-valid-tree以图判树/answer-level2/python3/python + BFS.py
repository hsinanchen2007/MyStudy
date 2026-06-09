```python
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if n == 1: return True # specical case
        rest = n
        adj = collections.defaultdict(list)
        queue = collections.deque()
        in_degree = [0] * n
        # Time complexity: O(N)
        # Space complexity: O(N)
        
        for a, b in edges:
            in_degree[b] += 1
            in_degree[a] += 1
            adj[a].append(b)
            adj[b].append(a)

        for i in range(n):
            if in_degree[i] == 1:
                queue.append(i)
                rest -= 1        
        while queue:
            node = queue.popleft()
            for neibor in adj[node]:
                in_degree[neibor] -= 1
                if in_degree[neibor] == 1:
                    queue.append(neibor)
                    rest -= 1
        return rest == 0 and len(edges) == n - 1
```