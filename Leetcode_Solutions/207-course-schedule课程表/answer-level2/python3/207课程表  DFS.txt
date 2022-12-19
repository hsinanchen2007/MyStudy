### 解题思路
#### 0.建立邻接表
和BFS一样建立
#### 1.递归基：
visited[i]==1,访问时已被自身顶点访问，说明有环，直接返回False
visited[i]==0,访问时已被其他顶点访问，说明无环，直接返回True
#### 2.递归：
顶点之前没被访问，标记为1（被自身访问）
搜索顶点邻居，若发现环则返回True
当前顶点的邻居访问完毕无环，则标记为-1。

### 代码

```python3
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        #建立邻接表（和BFS+入度表一样）
        adjacency=[[] for _ in range(numCourses)]
        for cur,pre in prerequisites:
            adjacency[pre].append(cur)
        #DFS
        visited=[0]*numCourses#用来判断顶点是否已访问:0未访问；1被当前顶点访问；-1被其他顶点访问
        def toposort(i,visited):
            #递归基
            if visited[i]==-1:return True#访问时已被其他顶点访问，说明没有环且访问结束
            if visited[i]==1:return False#访问时已被自身顶点访问过，说明有环，退出返回False
            #递归
            if visited[i]==0:#之前没被访问过，标记访问
                visited[i]=1
            for nbr in adjacency[i]:
                swc=toposort(nbr,visited)
                if not swc:return False#发现环，返回False
            visited[i]=-1#当前顶点的邻居访问完毕未发现环，标记访问完毕
            return True
        for i in range(numCourses):
            if not toposort(i,visited):return False
        return True

                
            
            
        
        

                    

        
```