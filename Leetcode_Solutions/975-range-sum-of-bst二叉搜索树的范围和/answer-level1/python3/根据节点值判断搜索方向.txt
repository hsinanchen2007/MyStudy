```
class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        def dfs(root):
            if root is None:
                return 0
            elif root.val < L:
                return dfs(root.right)
            elif root.val > R:
                return dfs(root.left)
            else:
                return dfs(root.left) + dfs(root.right) + root.val
        return dfs(root)
```
