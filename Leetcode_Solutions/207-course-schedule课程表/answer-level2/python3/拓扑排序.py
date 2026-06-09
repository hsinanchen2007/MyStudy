```python
from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        in_degree = [0] * numCourses
        for c0, c1 in prerequisites:
            adj[c1].append(c0)
            in_degree[c0] += 1
        queue = [i for i in range(numCourses) if in_degree[i] == 0]
        cnt = 0
        while queue:
            c = queue.pop()
            cnt += 1
            for c1 in adj[c]:
                in_degree[c1] -= 1
                if in_degree[c1] == 0:
                    queue.append(c1)
        return cnt == numCourses

    def canFinish1(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        for c0, c1 in prerequisites:
            adj[c0].append(c1)

        res = True
        visited = set()

        def dfs(c: int, path: set) -> None:
            nonlocal res
            if not res or c in visited: return
            if c in path:
                res = False
                return
            for i in adj[c]:
                dfs(i, path | {c})
            visited.add(c)

        for i in range(numCourses):
            dfs(i, set())
        return res
```