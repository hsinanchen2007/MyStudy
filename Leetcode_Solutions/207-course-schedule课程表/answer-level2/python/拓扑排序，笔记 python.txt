### 解题思路
主要是对精讲高赞题解的代码注释，用的是广搜。

### 代码

```python3
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        #用拓扑排序，来判断图是否是有环图
        #首先定义两个表，一个入度表，一个图的邻接表
        indegrees = [0 for _ in range(numCourses)]
        adjacency = [[] for _ in range(numCourses)]

        #将题目给出的数据转换成入度表和邻接表
        for cur, pre in prerequisites:
            indegrees[cur] += 1
            adjacency[pre].append(cur)

        #然后开始用bfs进行，首先将入度为0的点入队
        quee_ = []
        for i in range(numCourses):
            if indegrees[i] == 0:
                quee_.append(i)

        #开始迭代
        while quee_:
            node = quee_.pop(0)
            numCourses-=1                    #学完一门课
            for c in adjacency[node]:
                indegrees[c] -= 1            #这个点入读减1
                if indegrees[c] == 0:        #入读变为0，意思已经学完了先到课程
                    quee_.append(c)          #入队,循环
        
        return not numCourses                #判断时候课程都学完

```