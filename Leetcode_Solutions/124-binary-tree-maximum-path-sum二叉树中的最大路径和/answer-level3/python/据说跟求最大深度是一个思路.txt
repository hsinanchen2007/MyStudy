### 解题思路
用的是递归思路
self.res = max(self.res, left + right + root.val) 
return max(0, max(left, right) + root.val)
这两句是重点

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.res = float("-inf")
        def helper(root):
            if not root:
                return 0
            left = helper(root.left)
            right = helper(root.right)
            self.res = max(self.res, left + right + root.val) 
            return max(0, max(left, right) + root.val)
        helper(root)
        return self.res
```