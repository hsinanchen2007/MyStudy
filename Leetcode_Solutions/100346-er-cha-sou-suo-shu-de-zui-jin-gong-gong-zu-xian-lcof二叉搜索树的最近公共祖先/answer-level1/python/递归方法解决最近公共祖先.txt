如果p或者q就是根节点，那么此时根节点就是最近公共祖先。
否则，一共可以分成两种情况进行讨论：
根据二叉搜索树特性：
一、根节点节点值在p，q两个节点根节点值之间，说明p，q位于根节点的两棵不同的子树上，那么此时根节点就是最近公共祖先。
二、如果节点值比p，q节点值大，说明p，q都在左子树上，那么递归的查找左子树。
三、如果节点值比p，q节点值小，说明p，q都在右子树上，那么递归的查找右子树。

代码：
```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if root == p:
            return p
        if root == q:
            return q
        if (p.val < root.val and q.val > root.val) or (p.val > root.val and q.val < root.val):
            return root
        if p.val > root.val and q.val > root.val:
            return self.lowestCommonAncestor(root.right,p,q)
        if p.val < root.val and q.val < root.val:
            return self.lowestCommonAncestor(root.left,p,q)
        
```

