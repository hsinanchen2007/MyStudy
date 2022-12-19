### 解题思路
题意问题可以转化成寻找有向图中是否存在环的问题

寻找图中入度为0的点，并删除入度为0的点，更新图
直到图中所有的点入度都不为0

如果此时图中依然有点，那么证明图中有环，返回False，否则返回True
### 代码

```python3
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegree = [0 for _ in range(numCourses)]
        son = {_:[] for _ in range(numCourses)}

        for i, j in prerequisites:
            indegree[i] += 1
            son[j].append(i)

        no_parent = []
        for i in range(len(indegree)):
            if indegree[i] == 0:
                no_parent.append(i)
        
        while no_parent:
            cur = no_parent.pop(0)
            numCourses -= 1
            for i in son[cur]:
                indegree[i] -= 1
                if indegree[i] == 0:
                    no_parent.append(i)
        return not numCourses

```