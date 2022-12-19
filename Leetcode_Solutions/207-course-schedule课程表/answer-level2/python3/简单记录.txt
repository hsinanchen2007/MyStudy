### 解题思路
拓扑排序思路（BFS）

1. 先初始化一个入度表，包含所有课程的入度（前继课程数量）。
2. 再初始化一个多维列表，来表示这张课程图。
3. 初始化一个空队列，将入度数为0的点入队。
4. 如果队列不为空，进入循环；将队头元素出列并将该元素的后继元素的入度数减一，再把入度数为0的元素放入队列中。

### 代码

```python
class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        indegree = [0 for _ in range(numCourses)]  # 生成一个入度表， 初始化为0
        graph = [[] for _ in range(numCourses)]  # 生成一个图，初始化为空列表

        for succ, pre in prerequisites:
            indegree[succ] += 1  # 写好入度表
            graph[pre].append(succ)  # 写好图

        queue = []
        total = 0
        for i in range(numCourses): # 将入读为0的店进入队列
            if indegree[i] == 0:
                queue.append(i)
        
        while queue:
            top = queue.pop()
            total += 1
            for i in graph[top]:
                indegree[i] -= 1
                if indegree[i] == 0:
                    queue.append(i)
        
        if total == numCourses:
            return True
        else:
            return False
```