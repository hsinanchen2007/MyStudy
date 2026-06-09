## 思路：

这道题 就是**找图中是否有环。**

思路一：深度优先遍历

时间复杂度：$O(N + E)$ $N$ 为顶点个数，$E$为边的个数

思路二：广度优先遍历

通过顶点的入度的个数，每次消除入度为`0`顶点，看是否每一个节点都能被消除

时间复杂度 ： $O(N + E)$ $N$ 为顶点个数，$E$为边的个数

## 代码：

DFS

```python
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        from collections import defaultdict
        graph = defaultdict(list)
        # 记录
        visited = set()
        # 建图
        for x, y in prerequisites:
            graph[y].append(x)

        # 深度遍历
        def dfs(i, being_visited):
            if i in being_visited: return False
            if i in visited: return True
            visited.add(i)
            being_visited.add(i)
            for j in graph[i]:
                if not dfs(j, being_visited): return False
            being_visited.remove(i)
            return True
        # 检测每门功课起始是否存在环
        for i in range(numCourses):
            # 已经访问过
            if i in visited: continue
            if not dfs(i, set()): return False
        return True
```

BFS

```python
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        from collections import defaultdict, deque
        graph = defaultdict(list)
        degree = [0] * numCourses
        # 建图
        for x, y in prerequisites:
            graph[y].append(x)
            degree[x] += 1
        queue = deque([i for i in range(numCourses) if degree[i] == 0])
        #print(queue)
        cnt = 0
        while queue:
            i = queue.pop()
            cnt += 1
            for j in graph[i]:
                degree[j] -= 1
                if degree[j] == 0:
                    queue.appendleft(j)
        return cnt == numCourses
```

