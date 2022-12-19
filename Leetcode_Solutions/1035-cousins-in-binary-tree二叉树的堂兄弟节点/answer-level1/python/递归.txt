### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import namedtuple

class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:

        nodeInfo = namedtuple('info', ['level', 'parent'])
        def helper(root, level, parent):
            if not root:
                return
            if root.val == x:
                self.infoX = nodeInfo(level=level, parent=parent)
            if root.val == y:
                self.infoY = nodeInfo(level=level, parent=parent)
            helper(root.left, level+1, root)
            helper(root.right, level+1, root)
        
        helper(root, 0, None)
        return self.infoX.level == self.infoY.level and self.infoX.parent != self.infoY.parent

```