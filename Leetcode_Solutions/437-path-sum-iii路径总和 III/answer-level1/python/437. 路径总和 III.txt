分析：用到了两个递归
第一个递归：用于遍历每个结点
第二个递归：从该节点开始向下找存在的路径个数

```
def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        if not root:
            return 0
        def dfs(root,sum):
            count=0  #记录路径个数
            if not root:
                return 0
            if root.val==sum:
                count+=1
            count+=dfs(root.left,sum-root.val)
            count+=dfs(root.right,sum-root.val)
            return count
        return dfs(root,sum)+self.pathSum(root.left,sum)+self.pathSum(root.right,sum)
```

