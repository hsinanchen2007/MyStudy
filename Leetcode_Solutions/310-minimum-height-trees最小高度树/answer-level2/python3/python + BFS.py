```python
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1: return [0] # sepcial case
        adj = collections.defaultdict(list)
        in_degree = [0] * n
        for a, b in edges:
            adj[a].append(b)
            adj[b].append(a)
            in_degree[a] += 1
            in_degree[b] += 1
        queue = collections.deque()
        rest = n
        for i in range(n):
            if in_degree[i] == 1:
                queue.append(i)
                rest -= 1
        while rest > 0 :
            for i in range(len(queue)) :
                node = queue.popleft()
                for neibor in adj[node]:
                    in_degree[neibor] -= 1
                    if in_degree[neibor] == 1:
                        queue.append(neibor)
                        rest -= 1
        return list(queue)
```