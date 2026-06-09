### 解题思路
关键需要增加用一个记忆表 memTable， 记录每个新生成节点

### 代码

```python

class Solution(object):
    def __init__(self):
        self.memTable = {}

    def cloneGraph(self, node):
        if not node: return None
        if self.memTable.get(node.val):
            return self.memTable[node.val]

        newNode = Node(node.val, None)
        self.memTable[node.val] = newNode

        neighbors = []
        for nb in node.neighbors:
            neighbors.append(self.cloneGraph(nb))
        newNode.neighbors = neighbors

        return newNode

```