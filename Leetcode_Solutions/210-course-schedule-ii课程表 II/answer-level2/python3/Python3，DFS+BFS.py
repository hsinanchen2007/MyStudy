DFS：
```
def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        res = []

        def dfs(i, adjacency, flags):
            if flags[i] == -1:
                return True
            if flags[i] == 1:
                return False
            flags[i] = 1
            for j in adjacency[i]:
                if not dfs(j, adjacency, flags):
                    return False
            flags[i] = -1
            res.append(i)
            return True

        adjacency = [[] for _ in range(numCourses)]
        flags = [0 for _ in range(numCourses)]
        for cur, pre in prerequisites:
            adjacency[pre].append(cur)
        for i in range(numCourses):
            if not dfs(i, adjacency, flags):
                return []
        return res[::-1]
```


BFS:
```
indegrees = [0 for _ in range(numCourses)]  # 入读表
        adjacency = [[] for _ in range(numCourses)]  # 邻接矩阵
        queue = []
        for cur, pre in prerequisites:
            indegrees[cur] += 1  # 得到入度
            adjacency[pre].append(cur)  # 得到每个课程节点的邻接表
        for i in range(len(indegrees)):
            if not indegrees[i]:
                queue.append(i)  # 把度为0的课程入队
        while queue:
            pre = queue.pop(0)
            numCourses -= 1  # 每次pre出队时，numCourses减1
            for cur in adjacency[pre]:
                indegrees[cur] -= 1  # 将这个节点的入度减1
                if not indegrees[cur]:  # cur的所有的前驱节点已经被删除，cur入队
                    queue.append(cur)
        return not numCourses  # 拓扑排序出队次数等于课程个数，课程安排图是否是有向无环图(DAG)，课程可以成功安排
```
