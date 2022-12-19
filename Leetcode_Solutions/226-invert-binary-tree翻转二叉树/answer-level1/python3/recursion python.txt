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

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root is None:
            return root
        
        elif root.left and root.right:
            temp = root.left
            root.left = root.right
            root.right = temp
            self.invertTree(root.left)
            self.invertTree(root.right)

        elif root.left:
            root.right = root.left
            root.left = None
            self.invertTree(root.right)

        else:
            root.left = root.right
            root.right = None
            self.invertTree(root.left)
        return root
```