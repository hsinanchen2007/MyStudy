 # 
    # 如果当前root值等于p q中的一个，直接返回root
    # 后边算法主要基于后续遍历：
    # 三种情况，p q 各在root的左右子树 返回 root
    #   p q全在root右子树 返回找到的右子树节点  全在左 返回左子树节点
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root: return None
        if root.val==p.val or root.val == q.val:
            return root
    
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if left and right:
            return root
        if left:
            return left
        if right:
            return right
        return None```
def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root: return None
        if root.val==p.val or root.val == q.val:
            return root
    
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if left and right:
            return root
        if left:
            return left
        if right:
            return right
        return None
```
