1、拓扑排序

这里用出度方便，注意邻接矩阵要重新生成

```
def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:  
    n, res = len(graph), []
    outdegrees = [len(graph[i]) for i in range(n)]
    adjacency = [[] for _ in range(n)]
    for i in range(n):
        for j in graph[i]:
            adjacency[j].append(i)

    queue = collections.deque()
    for i in range(n):
        if outdegrees[i] == 0: 
            queue.append(i)               
    while queue:
        node = queue.popleft()
        res.append(node)
        for i in adjacency[node]:
            outdegrees[i] -= 1
            if outdegrees[i] == 0:
                queue.append(i)                    
    return sorted(res)
```

2、DFS

这里要记录整体的已访问节点，和每个路径中的节点

```
def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]: 
    def dfs(node, path):
        if node in visited: 
            return visited[node]            
        if node not in path:
            visited[node] = all([dfs(i, path | {node}) for i in graph[node]]) if graph[node] else True                    
        else:
            visited[node] = False
        return visited[node]

    n, visited = len(graph), {}
    for i in range(n):            
        if i not in visited: dfs(i, set())                
    return [i for i in range(n) if visited[i]]
```


