### 解题思路
思路不断找度为零的，使得它连接点的度减一，度为零，进队

### 代码

```python
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adjMatrix=[[] for _ in range(numCourses)]
        defree = [0]*numCourses
        queue = []
        for cur, pre in prerequisites:
            adjMatrix[pre].append(cur)
            defree[cur]+=1
        for i in range(numCourses):
            if defree[i]==0:
                queue.append(i)
        while queue:
            pre = queue.pop(0)
            numCourses-=1
            for cur in adjMatrix[pre]:
                defree[cur]-=1
                if defree[cur]==0:
                    queue.append(cur)
        return not numCourses

```