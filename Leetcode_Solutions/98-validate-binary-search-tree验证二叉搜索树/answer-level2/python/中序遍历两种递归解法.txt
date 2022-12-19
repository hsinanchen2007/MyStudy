```
*1、二叉搜索树性质：中序遍历后，得到从小到大排序的数组*
*2、判断数组前后差值是否大于0*
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
 *优化上述中序遍历，缓存一个值，比较上一个值，节省空间*
```
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def search(node):
            if node==None:
                return
            
            search(node.left)
            if self.pre!=-float('inf') and self.pre >= node.val:
                self.flag = False
                return
            self.pre = node.val
            search(node.right)
        
        self.pre = -float('inf')
        self.flag = True
        search(root)
        return self.flag
```
