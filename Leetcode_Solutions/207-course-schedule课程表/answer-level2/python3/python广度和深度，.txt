2种思想，3种方法。代码里有注释。

```
from collections import defaultdict
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        return self.bfs_batch(numCourses, prerequisites)
        # return self.bfs(numCourses, prerequisites)
        # return self.dfs(numCourses, prerequisites)

    def dfs(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = defaultdict(set)  # 邻接表
        for j, i in prerequisites:
            adj[i].add(j)  # 邻接表
            # adj[j].add(i) # 逆邻接表

        # 访问标志：0 未访问，1 可以完成，-1 当前在访问
        flags = [0 for i in range(numCourses)]

        # dfs 函数
        def can(i):
            if flags[i] == 1:  # 之前访问过且可以完成，不用继续
                return True
            elif flags[i] == -1:  # 重复标记，有循环
                return False
            flags[i] = -1  # 访问前：标记要被访问
            for j in adj[i]:  # 递归访问
                if not can(j):
                    return False
            flags[i] = 1  # 访问后：可以完成
            return True

        # 逐个访问
        for i in range(numCourses):
            if not can(i):
                return False
        return True

    def bfs(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        in_deg = [0 for _ in range(numCourses)]  # 入度
        adj = defaultdict(set) # 邻接表
        for j, i in prerequisites:
            adj[i].add(j)
            in_deg[j] += 1
            
        q = [i for i, d in enumerate(in_deg) if not d]
        while q:
            i = q.pop(0) # can use the builtin queue to speed up
            numCourses -= 1 # 访问完一个
            for j in adj[i]:
                in_deg[j] -= 1 # 调整入度
                if not in_deg[j]: # 入度为0的节点入栈
                    q.append(j)
        return not numCourses
            
        
    def bfs_batch(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        in_deg = {i: 0 for i in range(numCourses)}  # 入度：用词典加速
        adj = defaultdict(set) # 邻接表
        for j, i in prerequisites:
            adj[i].add(j)
            in_deg[j] += 1

        # 删除入度为0的节点
        zvs = True
        while zvs:
            zvs = [i for i, d in in_deg.items() if d == 0]  # 找到入度为0的节点
            for v in zvs:
                for k in adj[v]:
                    in_deg[k] -= 1  # 子节点的入度-1
                del adj[v], in_deg[v]  # 删除节点
        return not in_deg  # 空
```
