**考虑两种情况：**（1）其中一个结点是另一个结点的祖先结点，则他们必然位于同一根结点的左子树或右子树上，这个节点就是最近公共祖先，所以返回p或q；（2）分别位于从某一根节点开始的的左子树和右子树上，这一根结点就是最近公共祖先，返回根结点

## 参考代码

    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        #导致递归返回的两种结果：
        if root == None:
            return None
        if root == p or root == q:
            return root
        
        #递归搜索左右子树
        res1 = self.lowestCommonAncestor(root.left, p, q)
        res2 = self.lowestCommonAncestor(root.right, p, q)
        
        #如果某一结果为Null，返回另一结果（也可能为Null）
        if res1 == None:
            return res2
        if res2 == None:
            return res1
        
        #如果都不为Null，返回根结点
        return root