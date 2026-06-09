### 解题思路
递归

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        def helper(root,s):
            if not root.left and not root.right:
                return sum==s
            return (True if root.left and helper(root.left,s+root.left.val) else False) or (True if root.right and helper(root.right,s+root.right.val) else False)
        return helper(root, root.val)
```