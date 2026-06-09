### 解题思路
在求深度时，多写一行res=max(res,l+r+1)来记录最大路径

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
        res=1
        def dfs(root):
            if not root:
                return 0
            l=dfs(root.left)
            r=dfs(root.right)
            nonlocal res
            res=max(res,l+r+1)
            return max(l,r)+1
        dfs(root)
        return res-1
            
```