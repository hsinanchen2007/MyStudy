### 解题思路
dfs(root) 根据 树是否是单值，返回true 或者 False

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isUnivalTree(self, root):
        def dfs(root):
            if not root:
                return True
            if root.left and root.left.val != root.val:
                return False
            if root.right and root.right.val != root.val:
                return False
            if not dfs(root.left):
                return False
            if not dfs(root.right):
                return False
            return True
        return dfs(root)
```