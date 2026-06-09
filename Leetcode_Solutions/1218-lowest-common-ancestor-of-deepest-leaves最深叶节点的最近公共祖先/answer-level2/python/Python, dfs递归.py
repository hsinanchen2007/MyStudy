```
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        # 返回该子树的答案以及该子树的深度
        def dfs(root) -> (TreeNode, int):
            if not root:
                return None, 0
            l_res, l_dep = dfs(root.left)
            r_res, r_dep = dfs(root.right)
            if l_dep == r_dep:
                return root, l_dep+1
            if l_dep > r_dep:
                return l_res, l_dep+1
            else:
                return r_res, r_dep+1
        return dfs(root)[0]
```
