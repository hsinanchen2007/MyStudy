首先，课程先后顺序可以理解为一个有向图，有解的条件是此图无环。因此我们可以依据其先后顺序构造有向图，并统计每门课程的入度（即其前一门课程的数量）。
```
rd = [0]*numCourses
edges = [[] for i in range(numCourses)]
for li in prerequisites:
    for i in range(len(li)-1):
        rd[li[i]]+=1
    for i in range(1,len(li)):
        edges[li[i]].append(li[i-1])
```
然后将入度为0的所有课程压入栈中，然后将这些课程的下一门课程的入度减1，减完后入度为0则入栈。重复上述操作直到栈为空。
如果最后存在入度不为为0的节点就说明有环，无解。
```
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        if numCourses<2:
            return [0]
        rd = [0]*numCourses
        edges = [[] for i in range(numCourses)]
        for li in prerequisites:
            for i in range(len(li)-1):
                rd[li[i]]+=1
            for i in range(1,len(li)):
                edges[li[i]].append(li[i-1])
        stack = []
        for i in range(numCourses):
            if rd[i]==0:
                stack.append(i)
        ans = []
        while stack:
            tmp = stack.pop()
            ans.append(tmp)
            for i in range(len(edges[tmp])):
                y = edges[tmp][i]
                rd[y]-=1
                if rd[y]==0:
                    stack.append(y)
        if len(ans)==numCourses:
            return ans
        return []
```