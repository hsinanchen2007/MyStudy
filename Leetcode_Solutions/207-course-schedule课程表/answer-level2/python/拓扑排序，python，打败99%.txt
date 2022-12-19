```python
from collections import defaultdict,deque
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj=defaultdict(list)
        degree=[0]*numCourses
        for s,e in prerequisites:
            adj[e].append(s)
            degree[s]+=1
        deq=deque([i for i in range(numCourses) if degree[i]==0])
        while(deq):
            cur,numCourses=deq.popleft(),numCourses-1
            for next in adj[cur]:
                degree[next]-=1
                if degree[next]==0:deq.append(next)
        return numCourses==0
```
