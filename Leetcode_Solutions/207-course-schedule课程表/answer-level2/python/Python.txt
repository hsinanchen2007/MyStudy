### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        innode=[0 for _ in range(numCourses)]
        lingjie=[[]for _ in range(numCourses)]
        for i,j in prerequisites:
            lingjie[j].append(i)
            innode[i]+=1
        queue=[]
        for i in range(len(innode)):
            if innode[i]==0:
                queue.append(i)
        while queue!=[]:
            cur=queue.pop()
            for x in lingjie[cur]:
                innode[x]-=1
                if innode[x]==0:
                    queue.append(x)
        for x in innode:
            if x!=0:
                return False
        return True
```