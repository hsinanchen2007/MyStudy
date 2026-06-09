```
class Solution:
    maxValue = float("-inf")
    def maxPathSum(self, root: TreeNode) -> int:
        if not root: return
        def helper(root):
            if not root: return 0
            l, r = helper(root.left), helper(root.right)
            self.maxValue = max(self.maxValue, l + r + root.val)
            return max(root.val + max(l,r), 0)
        helper(root)
        return self.maxValue
```
