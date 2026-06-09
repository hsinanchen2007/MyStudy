```
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        self.res = 0
        def dfs(node, _sum):
            if node:
                _sum = _sum * 10 + node.val
                if not node.left and not node.right:
                    self.res += _sum
                dfs(node.left, _sum)
                dfs(node.right, _sum)
        dfs(root, 0)
        return self.res
```
