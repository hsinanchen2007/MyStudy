## 思路：

意思按照什么顺序可以把所有功课学完

和[207. 课程表](https://leetcode-cn.com/problems/course-schedule/) | [题解链接](https://leetcode-cn.com/problems/course-schedule/solution/dfs-bfs-by-powcai) 一样，只是把过程记录下来！

思路一：BFS

思路二：DFS

如有不清楚的地方， 欢迎留言~

## 代码：

思路一：BFS

```python
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        from collections import defaultdict
        graph = defaultdict(list)
        degree = [0] * numCourses
        # 建图
        for x, y in prerequisites:
            graph[y].append(x)
            degree[x] += 1
        res = []
        bfs = [i for i in range(numCourses) if degree[i] == 0]
        #print(bfs)
        for i in bfs:
            res.append(i)
            for j in graph[i]:
                degree[j] -= 1
                if degree[j] == 0:
                    bfs.append(j)
        return res if len(res) == numCourses else []
```

思路二：DFS

```python
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        from collections import defaultdict
        graph = defaultdict(list)
        for x, y in prerequisites:
            graph[y].append(x)
        res = []
        visited = set()

        def dfs(i, being_visited):
            if i in being_visited:
                return False
            if i in visited:
                return True
            visited.add(i)
            being_visited.add(i)
            for j in graph[i]:
                if not dfs(j, being_visited):
                    return False
            being_visited.remove(i)
            res.append(i)
            return True
        for i in range(numCourses):
            if not dfs(i, set()):
                return []
        return res[::-1]
```

