方法一，dfs
```
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = []):
        self.val = val
        self.neighbors = neighbors
"""
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        visited=dict()  #哈希表中存放的是源node到克隆node的映射

        def dfs(node):
            if not node:
                return None
            if node in visited:
                return visited[node]

            clone=Node(node.val)    #如果这个节点没有被访问，也就没有被克隆
            visited[node]=clone     #源节点-克隆节点

            for neighbor in node.neighbors:
                clone.neighbors.append(dfs(neighbor))   #在返回前需要把邻居节点访问好，放进来，连通图，可以访问到全部节点
            return clone    #返回的是克隆好的节点
        return dfs(node)
```
方法二，bfs
```
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = []):
        self.val = val
        self.neighbors = neighbors
"""
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None

        from collections import deque
        
        queue=deque([node])
        visited=dict()
        visited[node]=Node(node.val)
        
        while queue:
            n=queue.popleft()

            for neighbor in n.neighbors:
                if neighbor not in visited: #如果没有访问，需要重新建立节点
                    visited[neighbor]=Node(neighbor.val)
                    queue.append(neighbor)  #队列中放入的是源节点
                visited[n].neighbors.append(visited[neighbor])  #无论如何，这个节点是当前方位节点的邻居，其它属性若没有等访问时添加

        return visited[node]
```
