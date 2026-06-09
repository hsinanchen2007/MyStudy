### 解题思路

思路1:
将边集合转换为邻接矩阵，利用BFS遍历 判断target是否可达
### 代码
```python3
class Solution:
    def findWhetherExistsPath(self, n: int, graph: List[List[int]], start: int, target: int) -> bool:
    graph_neigh = {}
    for i in range(n):
        graph_neigh[i] = set()

    for node in graph:
        graph_neigh[node[0]].add(node[1])
    
    ### BFS 依次将访问过的节点的未访问过的邻居节点压入栈中
    visited_Node = [False]*n
    visited_Node[start] = True
    pstack = [start] 
    while pstack != []:
        node = pstack.pop()
        visited_Node[node]=True
        for neigh in graph_neigh[node]:
            if not visited_Node[neigh]:
                pstack.append(neigh)
    
        return visited_Node[target]
```
### 解题思路

思路2
循环，思路类似BFS，不过省去了建立邻接矩阵的需要，即通过循环迭代，将访问过的节点的邻居节点存入集合中；当节点数量在一次循环后不再新增时，即认为所有的start可达节点已经加入集合中
### 代码

```python3
class Solution:
    def findWhetherExistsPath(self, n: int, graph: List[List[int]], start: int, target: int) -> bool:
        s=set([start])
        count=1
        while 1:
            for edged in graph:
                if edged[0] in s:
                    s.add(edged[1])
            if count == len(s):
                break
            else:
                count = len(s)
    
        return target in s
```

