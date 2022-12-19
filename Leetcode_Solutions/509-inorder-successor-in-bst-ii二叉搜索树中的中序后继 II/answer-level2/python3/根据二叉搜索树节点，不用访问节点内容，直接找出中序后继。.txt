### 解题思路
如果当前节点的右孩子存在，则将当前节点变为右孩子，寻找这个右孩子的最左节点
如果当前节点的右孩子不存在，如果孩子节点的父节点的右孩子节点等于当前节点，
则把当前节点变为父节点，一直循环下去，如果父节点为空，则返回none，否则返回当前节点的父节点。

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""
class Solution:
    def inorderSuccessor(self, node: 'Node') -> 'Node':

        cur = node

        if cur.right:
            cur = cur.right
            while cur.left:
                cur = cur.left
            return cur

        else:
            while cur.parent and (cur.parent.right == cur):
                cur = cur.parent

            return cur.parent
```