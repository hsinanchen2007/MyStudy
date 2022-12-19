```
class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        res = []

        def bfs(root, level=0):
            if not root:
                return
            if len(res) == level:
                res.append(float('-inf'))
            res[level] = max(res[level], root.val)
            bfs(root.left, level + 1)
            bfs(root.right, level + 1)
        bfs(root)
        return res
```
