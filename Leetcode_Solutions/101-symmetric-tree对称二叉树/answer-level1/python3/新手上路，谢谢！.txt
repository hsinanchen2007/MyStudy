### 解题思路
1. 左边的左子树和右边的右子树对称
2. 左边的右子树和右边的左子树对称
3. 2个根结点的值要相等

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        return self.dfs(root.left, root.right)
    
    def dfs(self, p, q):
        if not p or not q:
            return not p and not q
        return p.val == q.val and self.dfs(p.left, q.right) and self.dfs(p.right, q.left)
        
```