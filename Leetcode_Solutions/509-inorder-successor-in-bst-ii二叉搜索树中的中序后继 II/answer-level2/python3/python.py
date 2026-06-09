```python
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
        # in_order successor
    
        if node.right: # search bottom
            node = node.right
            while node.left: node = node.left
            return node
        # search top
        while node.parent and node == node.parent.right:
            node = node.parent
        return node.parent

```