### 解题思路
与207课程表相似，入度为0则入队，出队时L.append(vertex)，最后判断是否还有剩余课程，若有则说明有环，若无则输出最后结果.

### 代码

```python3
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        from collections import deque
        #建立邻接表和入度表
        adjacency=[[] for _ in range(numCourses)]
        indegree=[0]*numCourses
        for cur,pre in prerequisites:
            adjacency[pre].append(cur)
            indegree[cur]+=1
        #BFS
        L=[]
        queue=deque()#入度为0的顶点入队
        for i in range(numCourses):
            if indegree[i] == 0:#入度为0
                queue.append(i)
        while queue:#直至队列无值
            cur=queue.popleft()#当前顶点出队
            L.append(cur)
            numCourses-=1
            for nbr in adjacency[cur]:#对cur的邻居搜索
                indegree[nbr]-=1
                if indegree[nbr]==0:
                    queue.append(nbr)
        return L if not numCourses else []


```