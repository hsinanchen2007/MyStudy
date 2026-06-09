思路简单， 复杂地 O（n^2）
class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        if not s: return False

        def aux(root1,root2):
            if not root1 and not root2:
                return True
            if None in [root1,root2] or root1.val != root2.val:
                return False
            return aux(root1.left,root2.left) and aux(root1.right,root2.right)
        
        return aux(s,t) or self.isSubtree(s.left,t) or self.isSubtree(s.right,t)