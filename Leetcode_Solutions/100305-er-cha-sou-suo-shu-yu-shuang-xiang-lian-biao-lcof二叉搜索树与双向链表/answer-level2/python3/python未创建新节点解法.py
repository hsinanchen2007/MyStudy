```
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if not root:
            return None
        queue = []
        def pre(root):
            if not root:
                return 
            pre(root.left)
            queue.append(root)
            pre(root.right)
        pre(root)
        head = queue.pop(0)
        cur = head
        while queue:
            temp = queue.pop(0)
            cur.right = temp
            temp.left = cur
            cur = cur.right
        cur.right = head
        head.left = cur
        return head
```
