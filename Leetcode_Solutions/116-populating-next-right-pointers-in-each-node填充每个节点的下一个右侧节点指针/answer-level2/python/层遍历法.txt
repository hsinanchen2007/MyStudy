### 解题思路
虽然没有遵守常数空间的要求，但是代码还是比较简洁

### 代码

```python
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution(object):
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        q = [(0, root)]
        while q:
            layer, node = q.pop(0)
            if node:
                if node.left:
                    q.append((layer+1, node.left))
                if node.right:
                    q.append((layer+1, node.right))
                if q and q[0] and q[0][0] == layer:
                    node.next = q[0][1]
        return root

```