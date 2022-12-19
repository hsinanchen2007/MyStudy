```python []
class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.R = 0
        self.dfs(root)
        return self.R
    
    def dfs(self,root):
        if not root:
            return 0
        l = self.dfs(root.left)
        r = self.dfs(root.right)
        # 更新二叉树的最长直径
        self.R = max(l+r,self.R)
        # 返回 该节点层数
        return max(l,r) + 1
```

