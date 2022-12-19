## 思路
本题是[207. 课程表](https://leetcode-cn.com/problems/course-schedule/)，[210. 课程表 II](https://leetcode-cn.com/problems/course-schedule-ii/)的变种题，三者都可以用拓扑排序解题。

## 思路
拓扑排序能有效解决有向图里节点存在依赖关系的问题，

其主要思想就三步：

1. 遍历整个图，生成入度数组并记录每个点的邻居节点
2. 新建一个队列，将所有入度为0的节点入队
3. 逐个删除掉队列里的头节点，并将删除节点的邻居节点的入度 - 1， 如果此时邻居节点的入度为0，则代表其所有的依赖关系都不存在了，因此可以将其入队

## Python代码
```Python
class Solution(object):
    def minimumSemesters(self, N, relations):
        """
        :type N: int
        :type relations: List[List[int]]
        :rtype: int
        """
        indegree = [0 for i in range(N + 1)]
        adj = [set() for _ in range(N + 1)]
        for pre, cur in relations: 
            indegree[cur] += 1 #统计入度
            adj[pre].add(cur) #统计邻居节点
            
        from collections import deque
        queue = deque()
        for i, x in enumerate(indegree):
            if x == 0 and i > 0: #将入度为0的节点入队
                queue.append(i)

        semester_cnt= 0
        finished_course = 0
        while queue:
            next_queue = deque()
            semester_cnt += 1 #新的学期来了

            for cur in queue: #此时queue里存放的是这个学期可以学的所有课      
                finished_course += 1 #又一门课学完了
                for neighbor in adj[cur]:
                    indegree[neighbor] -= 1
                    if indegree[neighbor] == 0:
                        next_queue.append(neighbor) #下个学期可以学neighbor这门课了

            queue = next_queue

        return semester_cnt if finished_course == N else -1 #如果所有的课都学完了，那么finished_course == N       
            
```
## 复杂度分析

时间复杂度： $O(N)$

空间复杂度： $O(N)$