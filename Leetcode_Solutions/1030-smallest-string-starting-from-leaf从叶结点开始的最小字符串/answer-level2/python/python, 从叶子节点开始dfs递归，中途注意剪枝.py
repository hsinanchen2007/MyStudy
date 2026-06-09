```python
    # 最直接的思路的dfs解法，用set来去重即剪枝
    def smallestFromLeaf(self, root: TreeNode) -> str:
        def dfs(root):
            alpha = chr(root.val+97)
            if not root.left and not root.right:
                return {alpha}
            if not root.left:
                return map(lambda i: i+alpha, dfs(root.right))
            if not root.right:
                return map(lambda i: i+alpha, dfs(root.left))
            return map(lambda i: i+alpha, set(dfs(root.right)) | set(dfs(root.left)))

        if not root:
            return ''
        return min(dfs(root))
```
