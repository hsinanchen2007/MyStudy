```

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        def check(root, sum):
            if root is None:
                return False
            if root.left is None and root.right is None:
                if sum == root.val:
                    return True
                else:
                    return False

            if check(root.left, sum-root.val):
                return True
            if check(root.right, sum-root.val):
                return True
            return False
        return check(root, sum)
```
