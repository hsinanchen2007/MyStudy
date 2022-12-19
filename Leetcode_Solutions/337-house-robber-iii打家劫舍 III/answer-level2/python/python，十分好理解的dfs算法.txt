```python
    def rob(self, root: TreeNode) -> int:
        def dfs(root: TreeNode) -> (int, int):  # 返回取根时的最大值和不取根时的最大值
            if not root:
                return 0, 0
            elif not root.left and not root.right:
                return root.val, 0
            left = dfs(root.left)
            right = dfs(root.right)
            return root.val + left[1] + right[1], \
                   max(left[0] + right[0], left[0] + right[1], left[1] + right[0], left[1] + right[1])
        return max(dfs(root))
```
