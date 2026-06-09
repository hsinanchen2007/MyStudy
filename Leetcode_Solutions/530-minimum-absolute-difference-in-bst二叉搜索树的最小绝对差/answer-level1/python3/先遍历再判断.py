```
class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        def f(node):
            if not node:
                return []
            return f(node.left) + [node.val] + f(node.right)
        vals = f(root)
        ans = abs(vals[0] - vals[1])
        for i in range(len(vals) - 1):
            ans = min(ans, abs(vals[i] - vals[i + 1]))
        return ans
```
