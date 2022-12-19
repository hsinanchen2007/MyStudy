**思路：** 前序遍历的起点肯定是当前子树的根结点，找到其在中序遍历列表中的位置，其左右两侧就是其左右子树，再分别查找左右子树的根结点和子树，如此递归下去，最后将左右子树接回到根结点上。

## 示例代码

    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        #边界条件
        if len(preorder) == 0:
            return None
        
        #记录中序遍历每个结点的位置
        dic = {}
        for index, value in enumerate(inorder):
            dic[value] = index
        
        #定义生成左右子树的函数
        def tree(lpre, rpre, lin, rin):
            if lpre > rpre:
                return None
            #前序的第一个值肯定是根结点
            root = TreeNode(preorder[lpre])
            if lpre == rpre:
                return root
            
            loc = dic[root.val]
            
            #递归生成左右子树
            left_tree = tree(lpre+1, lpre+loc-lin, lin, loc-1)
            right_tree = tree(lpre+loc-lin+1, rpre, loc+1, rin)
            
            #将左右子树接回到根结点上
            root.left = left_tree
            root.right = right_tree
            
            return root
        
        return tree(0, len(preorder)-1, 0, len(inorder)-1)