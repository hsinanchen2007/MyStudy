### 解题思路
图的深度优先遍历找是否存在环!

flag[i]==1代表i被访问过, 且从i出发之后都无环, flag[i]==-1代表i被访问过且i之后有环

### 代码

```python3
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        def dfs(i, d, flag):
            if flag[i]==1: return True
            elif flag[i]==-1: return False
            flag[i] = -1
            for j in d[i]:
                if not dfs(j, d, flag): return False
            flag[i] = 1
            return True
        
        adj = [[] for  _ in range(numCourses)] # 因为一个节点可能指向多个节点
        flag = [0]*numCourses
        for p in prerequisites:
            adj[p[0]].append(p[1])
        for i in range(numCourses):
            if not dfs(i, adj, flag): return False
            numCourses -= 1
        return numCourses==0


```

广度遍历, 其实应该也可以看作是图的拓扑排序
拓扑排序原理： 对 DAG 的顶点进行排序，使得对每一条有向边 (u, v)(u,v)，均有 uu（在排序记录中）比 vv 先出现。亦可理解为对某点 vv 而言，只有当 vv 的所有源点均出现了，vv 才能出现。

算法流程：
统计课程安排图中每个节点的入度，生成 入度表 indegrees。
借助一个队列 queue，将所有入度为 00 的节点入队。
当 queue 非空时，依次将队首节点出队，在课程安排图中删除此节点 pre：
并不是真正从邻接表中删除此节点 pre，而是将此节点对应所有邻接节点 cur 的入度 -1−1，即 indegrees[cur] -= 1。
当入度 -1−1后邻接节点 cur 的入度为 00，说明 cur 所有的前驱节点已经被 “删除”，此时将 cur 入队。
在每次 pre 出队时，执行 numCourses--；
若整个课程安排图是有向无环图（即可以安排），则所有节点一定都入队并出队过，即完成拓扑排序。换个角度说，若课程安排图中存在环，一定有节点的入度始终不为 00。
因此，拓扑排序出队次数等于课程个数，返回 numCourses == 0 判断课程是否可以成功安排。

作者：jyd
链接：https://leetcode-cn.com/problems/course-schedule/solution/course-schedule-tuo-bu-pai-xu-bfsdfsliang-chong-fa/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

```
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
       
        from collections import deque       
        q = deque() 
        adj = [[] for  _ in range(numCourses)]
        degree = [0]*numCourses # 记录每个节点的入度
        l = numCourses
        for p in prerequisites:
            adj[p[0]].append(p[1])
            degree[p[1]] += 1
        for i in range(numCourses): # 入度为0的结点进入队列,也只有入度为0的结点会被加入队列,下面的循环中也是
            if degree[i]==0: q.append(i)
        while q:
            cur = q.popleft() # 
            numCourses -= 1
            for j in adj[cur]:
                degree[j] -= 1 # 删去一个节点,则其连接的所有结点的入度减1
                if not degree[j]: q.append(j) 
        return numCourses==0 # 若无环,则到最后所有的结点入度都应该为1
```