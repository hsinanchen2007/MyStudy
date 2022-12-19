类似中序遍历的方法，区别在于只有对左节点进行操作，适用于不限制内存空间的情况。

def upsideDownBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root==None:
            return root
        if root.left==None and root.right ==None:
            return root
        p = root
        stack = []
        roots = None
        while p:
            stack.append(p)
            p = p.left
        result = None
        roots = None
        while stack!=[]:
            node = stack.pop()
            if roots==None:
                roots = TreeNode(node.val)
                result = roots
                continue
            else:
                roots.left = node.right
                roots.right = TreeNode(node.val)
                roots = roots.right    
        return result