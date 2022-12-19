```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        if not root:
            return 0
        self.result = 0
        def helper(root, flag):
            if not root:
                return
            if not root.left and not root.right and flag==1:
                self.result+=root.val
            helper(root.left,1)
            helper(root.right,-1)
        helper(root,0)
        return self.result
```