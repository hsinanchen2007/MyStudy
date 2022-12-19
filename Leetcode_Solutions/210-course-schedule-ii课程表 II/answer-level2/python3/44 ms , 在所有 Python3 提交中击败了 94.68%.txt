### 解题思路
和207题一样,
主要是要构造出一个图, 然后在图上进行拓扑排序判断是否有环,
dfs用flag标记每个节点, bfs用入度表记录每个节点的入度 
dfs, 只不过要在中间记录结点的路程
最后翻转一下


### 代码

```python3
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        def dfs(i, adj, flag, res):
            if flag[i]==1: return True # 不能写成if flag[i], 不然-1也会被判定为True
            elif flag[i]==-1: return False
            flag[i] = -1
            for j in adj[i]:
                if not dfs(j, adj, flag, res): return False
            flag[i] = 1
            res.append(i)
            return True
        
        adj = [[] for _ in range(numCourses)]
        flag = [0]*numCourses
        for p in prerequisites:
            adj[p[1]].append(p[0]) # 这里注意是p[1]->p[0], 因为p[0]>p[1], 所以是从小值开始
        res = []
        for i in range(numCourses):
            if not dfs(i, adj, flag, res): return []
        return res[::-1]
```

如果构造图的时候想p[0]->p[1], 则最后遍历的顺序也反一下就行
```
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        def dfs(i, adj, flag, res):
            if flag[i]==1: return True
            elif flag[i]==-1: return False
            flag[i] = -1
            for j in adj[i]:
                if not dfs(j, adj, flag, res): return False
            flag[i] = 1
            res.append(i)
            return True
        
        adj = [[] for _ in range(numCourses)]
        flag = [0]*numCourses
        for p in prerequisites:
            adj[p[0]].append(p[1]) # 构造的图是p[0]->p[1]
        res = []
        for i in range(numCourses-1, -1, -1): # 最后遍历的时候要从numcourse-1开始
            if not dfs(i, adj, flag, res): return []
        return res # 不用reverse了
```