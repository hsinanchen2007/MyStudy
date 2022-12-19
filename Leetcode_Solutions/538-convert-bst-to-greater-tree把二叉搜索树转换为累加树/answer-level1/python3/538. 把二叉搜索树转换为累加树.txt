分析：先遍历右节点，再存储根节点，最后遍历左节点
```
class Solution(object):
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.sum=0
        def dfs(root):
            if not root:
                return
            dfs(root.right)
            self.sum+=root.val
            root.val=self.sum
            dfs(root.left)
        dfs(root)

```

