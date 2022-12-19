### 解题思路
rt

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
        def helper(root):
            if not root:
                return 0
            return 1 + max(helper(root.left), helper(root.right))
        return helper(root)
```