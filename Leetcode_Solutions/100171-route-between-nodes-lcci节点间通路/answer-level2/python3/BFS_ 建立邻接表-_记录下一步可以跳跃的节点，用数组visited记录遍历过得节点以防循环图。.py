```python
class Solution:
    def findWhetherExistsPath(self, n: int, graph: List[List[int]], start: int, target: int) -> bool:
        link_table = [[] for _ in range(n)]
        visited = [0 for i in range(n)]
        for i, j in graph:
            link_table[i].append(j)
        curr = [start]
        next_node = []

        while curr:
            for node in curr:
                if target in link_table[node]:
                    return True
                for j in link_table[node]:
                    if not visited[j]:
                        next_node += [j] 
                        visited[j] = 1
            curr = next_node
            next_node = []
        return False
