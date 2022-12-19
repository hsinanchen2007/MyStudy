### 解题思路
1.使用递归函数隐式的调用栈
2.注意visited={}放在递归函数之外
3.递归基：
1).若无Vertex，则直接返回；
2)若出现在visited中返回visited[node]
4.递归：对每个邻居进行搜索，克隆加到现在node的neighbors上


### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = []):
        self.val = val
        self.neighbors = neighbors
"""
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        visited={}#定义在递归函数之外
        def dfs(node):
            #DFS 通过递归调用隐式的使用栈
            if not node:return node 
            if node in visited:
                return visited[node]
            #sear=[]
            curNode=Node(node.val,[])
            visited[node]=curNode
            for nbr in node.neighbors:#若有邻居
                curNode.neighbors.append(dfs(nbr))#对每个邻居进行深入
            return curNode
        return dfs(node)
```