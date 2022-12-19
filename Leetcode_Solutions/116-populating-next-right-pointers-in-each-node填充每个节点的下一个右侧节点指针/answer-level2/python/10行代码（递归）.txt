### 解题思路
思路代码都很简单，但是这看起来更像dfs。。。

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root: return None
        def con(t1, t2):
            t1.next = t2
            t2.next = None
            if t1.right and t2.left:
                con(t1.left, t1.right)
                con(t1.right, t2.left)
                con(t2.left, t2.right)
        con(root, root)
        return root
            
```