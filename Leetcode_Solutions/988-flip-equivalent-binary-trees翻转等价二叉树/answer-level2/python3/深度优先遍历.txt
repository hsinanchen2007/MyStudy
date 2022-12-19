### 解题思路
考虑翻转后是否相等或者不翻转是否相等

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flipEquiv(self, root1: TreeNode, root2: TreeNode) -> bool:
        def dfs(root1, root2):
            if not root1 and not root2:
                return True
            if not root1 or not root2:
                return False
            if root1.val != root2.val:
                return False
            if dfs(root1.left, root2.right) and dfs(root1.right, root2.left):
                return True
            if dfs(root1.left, root2.left) and dfs(root1.right, root2.right):
                return True
            return False
        return dfs(root1, root2)
            
```