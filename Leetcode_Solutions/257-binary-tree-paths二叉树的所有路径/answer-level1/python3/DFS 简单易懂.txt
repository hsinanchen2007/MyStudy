```
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        if not root: return []
        paths = []
        def dfs(root, path=""):
            path = path + str(root.val) + '->'
            if not root.left and not root.right:
                paths.append(path[:-2])
                return
            if root.left:
                dfs(root.left, path)
            if root.right:
                dfs(root.right, path)
        
        dfs(root)
        
        return paths
```
