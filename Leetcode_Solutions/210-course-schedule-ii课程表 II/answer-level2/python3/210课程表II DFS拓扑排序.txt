### 解题思路
与207课程表类似：
1.建立邻接表
2.visited中每个元素包含0：未访问，1：正在访问，-1：访问完成。这三种状态
3.如果有环，标记有环，直接返回
4.开始访问i时标记为正在访问；邻居顶点都访问结束，标记i为访问完成；若邻居节点访问状态为正在访问，说明这个邻居还没访问结束，即存在环。


### 代码

```python3
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        #建立邻接表
        adjacency=[[] for _ in range(numCourses)]
        for cur,pre in prerequisites:
            adjacency[pre].append(cur)
        #DFS
        visited=[0]*numCourses
        L=[]
        is_posible=True#判断是否有环（False）
        def toposort(i,visited,L):
            nonlocal is_posible#由于要修改is_posible，声明为nonlocal
            if not is_posible:return#若有环则返回
            if visited[i]==0:#若之前未访问
                visited[i]=1#标记为正访问
            for nbr in adjacency[i]:#对邻居顶点搜索
                if visited[nbr]==0:#若邻居节点为未访问状态
                    toposort(nbr,visited,L)#深入搜索
                elif visited[nbr]==1:#若邻居顶点访问时状态为正在访问，说明有环
                    is_posible=False
            visited[i]=-1#邻居节点处理结束，标记访问结束
            L.insert(0,i)#i入栈
            
        for i in range(numCourses):#对每个顶点都进行搜索
            if visited[i]==0:#若未访问
                toposort(i,visited,L)#进行拓扑排序
        return L if is_posible else []
```