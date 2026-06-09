```
class Solution:
    def countUnivalSubtrees(self, root):
        if not root: return 0
        ans,cur,root.uni=0,True,True
        if root.left:
            ans+=self.countUnivalSubtrees(root.left)
            root.uni&=root.left.uni and root.val==root.left.val
        if root.right:
            ans+=self.countUnivalSubtrees(root.right)
            root.uni&=root.right.uni and root.val==root.right.val
        return ans+1 if root.uni else ans
```
