### 解题思路
此处撰写解题思路
使用递归遍历树，所有left换成right，所有right换成left
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
            return
        root.left, root.right = self.invertTree(root.right),self.invertTree(root.left)
        return root
```