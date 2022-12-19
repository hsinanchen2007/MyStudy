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
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
    
  
        nu=0
        def dfs(root):
            if root==None:
                return 0
            le = dfs(root.left)
            ri = dfs(root.right)
            nonlocal nu
            nu = max(nu,le+ri)
            return max(le+1,ri+1)
        dfs(root)
        return nu
```