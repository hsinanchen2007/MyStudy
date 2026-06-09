### 解题思路

    从第一个节点开始：
        如果该节点没有边， 则跳过
        将当前节点放入队列Q，开始宽度优先搜索
            交换A、B
            Q中所有节点出队tmp(上一步是在A中，本步变成B中了)
            将tmp中节点的相邻节点tmp2在B中，返回失败
            将tmp中节点的相邻节点tmp2放入A，并入队Q
            邻接矩阵中删除tmp中节点的边
            

### 代码

```python
import collections
class Solution(object):
    def isBipartite(self, graph):       
        for i in range(len(graph)):
            if not graph[i]:continue

            A, B, Q = set(), set(), collections.deque()
            Q.append(graph[i][0])
            while Q:
                A, B, n = B, A, len(Q)
                for j in range(n):
                    tmp = Q.popleft()
                    for tmp2 in graph[tmp]: 
                        if tmp2 in B:
                            return False
                        if tmp2 not in A:
                            A.add(tmp2)
                            Q.append(tmp2)
                    graph[tmp] = []
            graph[i] = []
        return True

```