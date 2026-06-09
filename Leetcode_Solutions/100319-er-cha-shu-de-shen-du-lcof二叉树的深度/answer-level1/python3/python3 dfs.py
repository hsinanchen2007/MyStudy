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
    def maxDepth(self, root: TreeNode) -> int:
        self.res=0
        def dfs(node,n):

            if not node:
                return
            self.res = max(self.res,n)
            dfs(node.left,n+1)
            dfs(node.right,n+1)
        dfs(root,1)
        return self.res

```