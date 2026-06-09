        res = 0

        def dfs(node):
            if node:
                if L <= node.val <= R:
                    nonlocal res
                    res += node.val
                if L < node.val:
                    dfs(node.left)
                if node.val < R:
                    dfs(node.right)

        dfs(root)
        return res