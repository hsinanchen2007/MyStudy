### 解题思路
用法：
    这道题有点难，先跳过。
解法：
    入度表 indegrees，统计课程安排图中每个节点的入度。
    Indegrees = [0,1] 表示课程0没有入度，也就是没有前提。课程1有入度，有一个前提。
    Adjacency = [[1], []] 表示课程0有一个后续课程1，课程1没有后续了。

### 代码

```python
class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        indegrees = [0 for _ in range(numCourses)]
        adjacency = [[] for _ in range(numCourses)]
        queue = deque()
        # Get the indegree and adjacency of every course.
        for cur, pre in prerequisites:
            indegrees[cur] += 1
            adjacency[pre].append(cur)
        # Get all the courses with the indegree of 0.
        for i in range(len(indegrees)):
            if not indegrees[i]: queue.append(i)
        # BFS TopSort.
        while queue:
            pre = queue.popleft()
            numCourses -= 1
            for cur in adjacency[pre]:
                indegrees[cur] -= 1
                if not indegrees[cur]: queue.append(cur)
        return not numCourses


```