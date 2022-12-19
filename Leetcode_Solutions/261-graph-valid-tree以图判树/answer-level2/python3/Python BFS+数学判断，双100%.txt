# 1. 思路：

根据维基百科的定义，**树是没有回路的连通图**，也就是说，我们需要判断两个条件：


**1. 是否存在回路**

**2. 是否是只有一个连通域的连通图**

# 1.1 回路问题：

一个常见的思路是针对其中的节点进行遍历，如果遍历后返回了节点，说明其中有回路。

但是我们可以从几何的角度思考：

**1. 边数：**

对于任意一个没有回路的连通图而言，不难想象，**如果其有n个节点，那么必然有n-1条边进行连接**，因此第一个判断条件为：

**判断边数是否为n-1： 即 len(edges) == n - 1**，如果不满足该条件，返回False

**2. 连接关系：**

当边数满足条件后，我们可以利用字典path对连接关系进行记录，用集合set记录与某点i相连的所有节点，对于连接关系[i,j]而言，我们可以分别在path中记录 path[i] = {j} 和 path[j] = {i}。

当所有关系记录完成后，所有和其他节点有连接关系的节点都记录在path中。如果path的长度与n不相等，说明有节点未参与连接，也就是有孤立节点，说明图不是树。因此第二个条件是：

**判断字典的长度是否为n： 即 len(path) == n**，如果不满足该条件，返回False

# 1.2 连通域个数：

连通域个数的计算可以参考  [323. 无向图中连通分量的数目](https://leetcode-cn.com/problems/number-of-connected-components-in-an-undirected-graph/)，其核心思想是BFS，具体解释见注释。

# 2. 代码

```
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if n == 1:                             # 特例，只有一个点时，必然为树
            return True

        if len(edges) != n - 1:                # 对于n个顶点的树而言
            return False                       # 需要满足条件：连通且无环
                                               # 那必然要正好有n-1条边
                                               # 如果边数太少，则有点被孤立
                                               # 如果边数太多，那必然成环

        path = collections.defaultdict(set)    # 利用字典记录连接关系
        for i,j in edges:                      
            path[i] |= {j}
            path[j] |= {i}
        
        if n!=len(path):                       # 如果字典的长度与节点个数不符
            return False                       # 说明字典中缺少某节点
                                               # 也就是说有节点未参与连通图的过程
                                               # 有孤立节点说明不是树
        
        connected = 0                          # 连通域的个数
        for num in range(n):                   # 对n个节点进行遍历
                                               # 如果num在graph中，进行操作
            if num in path:
                queue = {num}                  # 建立队列{num}以便写bfs算法
                                               # 队列保存的是一组连通的点
                while queue:
                    i = queue.pop()            # 从队列中弹出数值i
                    if i in path:              # 如果i在图中
                        queue |= path[i]       # 将与i相连的节点加入队列
                        del path[i]            # 并删除graph[i]
                                               # 防止重复遍历
                
                connected += 1                 # 当该组所有连通的点被遍历结束, 结果+1
                if connected > 1:              # 连通域超过1一个时，不符合树的条件
                    return False               # 返回False

        return True                           

```

# 3. 提交结果

![11.png](https://pic.leetcode-cn.com/1c1aab301b6295b1c7111ffaef6018a3f0d9f2474f0e3e0a996c6644d19897dd-11.png)

