
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if root == None:
            return None
        node = root

        right = self.mirrorTree(node.right)
        left = self.mirrorTree(node.left)
        node.right = left
        node.left = right
        return root
```