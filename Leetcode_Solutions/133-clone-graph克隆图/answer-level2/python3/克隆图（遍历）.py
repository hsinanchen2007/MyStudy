### 解题思路
1. 为了完成连通图的深拷贝，首先要想如何将这个连通图的所有节点保存起来；我这里采用了列表或字典（键是原来节点，值就是相应拷贝节点）；
2. 将所有节点保存完成之后，关键点就是将原来的节点连接关系（即图上的边）拷贝到新的节点中；（具体见代码，即将node.neighbors补充完整）；
本题中用字典更加方便

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors
"""
class Solution:
    """
    无向连通图的深拷贝：基于遍历的方法
    1. 从node节点开始，将连通图的所有节点保存到nodelist这个列表中；
    2. 构造一个和nodelist同样大小的新列表newNodeList，将nodelist中的节点值和连接关系复制到newNodeList中
    注意，本题中即使你深拷贝了连通图，但是如果你返回的节点不是cloneGraph(node)方法中的传入节点node的复制节点，也可能无法通本题
    ps: 如果用列表保存连通图的节点，在时间复杂度上比较大；改用字典结构，能提高寻找速度；
    """
    
    def cloneGraph(self, node: 'Node') -> 'Node':
        # 由于发现本题返回最好是node节点对应的拷贝节点，否则即使拷贝过去也无法通过，因此将node节点备份一下
        start = node
        # nodelist为字典结构：其健是连通图原来的节点，值是拷贝后的节点
        nodelist = dict()
        visited = [node]
        nodelist[node] = Node(node.val, [])

        # 遍历整个连通图，将所有节点保存到nodelist中
        while visited:
            node = visited.pop()
            for n in node.neighbors:
                if n not in nodelist:
                    visited.append(n)
                    nodelist[n] = Node(n.val, [])

        # 复制连通图的连接关系
        for key in nodelist.keys():
            # 将与nodelist[key]连接的节点放入nodelist[key].neighbors中
            for n in key.neighbors:
                nodelist[key].neighbors.append(nodelist[n]) 
        
        # 返回node节点的深拷贝
        return nodelist[start]
```

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors
"""
class Solution:
    """
    基于列表结构的
    """
    
    def cloneGraph(self, node: 'Node') -> 'Node':

        nodelist = []
        visited = [node]
        nodelist.append(node)
        while visited:
            node = visited.pop()
            for n in node.neighbors:
                if n not in nodelist:
                    visited.append(n)
                    nodelist.append(n)
        # nodelist = list(nodelist)
        
        newNodeList = [Node(0,[]) for _ in range(len(nodelist))]

        for i in range(len(nodelist)):
            newNodeList[i].val = nodelist[i].val
            for n in nodelist[i].neighbors:
                index = nodelist.index(n)
                newNodeList[i].neighbors.append(newNodeList[index])
        
        return newNodeList[0]
```

            