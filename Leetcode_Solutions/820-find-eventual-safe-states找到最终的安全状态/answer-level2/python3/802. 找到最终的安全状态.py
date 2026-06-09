1. 这道题还是有点难，主要是一开始没看出来这个拓扑排序，网上大多数采用的也是DFS和BFS，有个人的BFS的版本还要维护图（需要删除图中的元素），这样效率怎么能高（即便使用set存储）。所以BFS的运行时间是DFS的二倍的。
2. 好了不说废话的，这个题需要找出的节点是没有出度的节点（以及把这些节点去掉之后没有出度的节点），这样可以看出其实就是一个拓扑排序的过程。注意并单单是寻找环中节点，那些节点指向环中的节点依然不是安全的节点（一开始没理解题意，以为是找环中的节点）。
3. 知道是拓扑排序就很好理解了。只需要一个逆邻接表再维护一个出度表就行了。出度为0就出名该节点是最终的节点了，这就是寻找的安全节点，再根据逆邻接表找出哪些节点连接找这个节点，将这个节点的出度减一。如果又有节点的出度是0则说明该节点也是安全节点。

## python3代码
```python3
class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        visit = [0]*n #该节点是否在最后的结果中，0表示不在，1表示在。也可以直接用列表存储最终的结果，但是还需要一个排序的过程。
        out_degree = [0] * n #记录该节点的出度
        reversed_graph = [[] for x in range(n)] #构建逆邻接表
        for cur in range(n):
            out_degree[cur] = len(graph[cur])
            for next in graph[cur]:
                reversed_graph[next].append(cur)

        queue = []
        result = []
        for i in range(n): # 出度为0的点入队
            if len(graph[i]) == 0:
                queue.append(i)
        while queue:
            cur = queue.pop(0)
            visit[cur] = 1
            for num in reversed_graph[cur]:
                #my_graph[num].remove(cur)
                out_degree[num] -= 1
                if(out_degree[num] == 0):
                    queue.append(num)
        for i in range(n):
            if(visit[i] == 1):
                result.append(i)
        return (result)
```