```python3
class Solution:
    def findWhetherExistsPath(self, n: int, graph: List[List[int]], start: int, target: int) -> bool:
        link_table = [[] for _ in range(n)]
        visited = [0 for _ in range(n)]
        for i,j in graph:
            link_table[i].append(j)
        cur = [start]
        node_next = []
        while cur:
            for i in range(len(cur)):
                for j in link_table[cur[i]]:
                    if target == j:
                        return True
                    if not visited[j]:
                        visited[j] = 1
                        node_next += [j]
            cur = node_next 
            node_next = []
        return False

