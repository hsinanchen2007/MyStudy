![image.png](https://pic.leetcode-cn.com/ee2011a82be23b7976d1f709e1d494c0ebfa1f66036a40f3aba47b1985daf1f4-image.png)



```
class Solution:

    def dfs(self, root: TreeNode, node_vals):
        if root is None:
            return

        node_vals.add(root.val)
        self.dfs(root.left, node_vals)
        self.dfs(root.right, node_vals)

    def search(self, root: TreeNode, node_vals, target):
        if root is None:
            return False

        if target - root.val in node_vals:
            return True

        return self.search(root.left, node_vals, target) or self.search(root.right, node_vals, target)

    def twoSumBSTs(self, root1: TreeNode, root2: TreeNode, target: int) -> bool:
        node_vals = set()
        self.dfs(root1, node_vals)
        return self.search(root2, node_vals, target)
```

