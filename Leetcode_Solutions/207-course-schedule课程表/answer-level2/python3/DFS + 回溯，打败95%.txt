思路：
通过输入的邻接表，构建一个有向图，在图中对所有未检查的节点进行DFS。调用`dfs(v)`时，查找的是一条从起点到v的有向路径，代码用`on_stack`变量来保存这条路径。 当找到路径v -> w 且 w 位于栈中时（`on_stack[w]==True`），说明同时存在一条w->v的路径，找到了环，课程无法完成。

```
from typing import List

class DirectedGraph:
    def __init__(self, n, edges):
        self.n = n
        self.adj_edges = [[] for _ in range(n)]
        for v, w in edges:
            self.adj_edges[w].append(v)
        self.visited = [False for _ in range(n)]
        self.on_stack = [False for _ in range(n)]
        self.cycle = None

        for v in range(self.n):
            if not self.visited[v]:
                self.dfs(v)

    def dfs(self, v):
        if self.visited[v]: return
        self.visited[v] = True
        self.on_stack[v] = True # v进入调用栈
        for w in self.adj_edges[v]:
            if self.cycle: 
                return
            if not self.visited[w]:
                self.dfs(w)
            elif self.on_stack[w]:
                self.cycle = True
                return
        self.on_stack[v] = False # 此时v将退出调用栈

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # build graph g
        di_g = DirectedGraph(numCourses, prerequisites)
        if di_g.cycle:
            return False
        return True

```
