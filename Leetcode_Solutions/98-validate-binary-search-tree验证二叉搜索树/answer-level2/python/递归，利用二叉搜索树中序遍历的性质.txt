*1、二叉搜索树性质：中序遍历后，得到从小到大排序的数组*
*2、判断数组前后差值是否大于0*
```
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def search(node):
            if not node:
                return
            search(node.left)
            self.list_.append(node.val)
            search(node.right)

        self.list_ = []
        search(root)
        if len(self.list_)==0:
            return True
        else:
            for i in range(len(self.list_)-1):
                if (self.list_[i+1] - self.list_[i])<=0:
                    return False
            return True
```
