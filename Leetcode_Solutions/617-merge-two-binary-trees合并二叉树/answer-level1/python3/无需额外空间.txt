感觉自己写的很复杂。。
```
class Solution(object):
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        if not t1 and not t2:return None
        elif not t1:return t2
        elif not t2:return t1
        def helper(t1,t2):
            if t1.left and t2.left:
                t1.left.val+=t2.left.val
                helper(t1.left,t2.left)
            elif t2.left:t1.left=t2.left
            if t1.right and t2.right:
                t1.right.val+=t2.right.val
                helper(t1.right,t2.right)
            elif t2.right:t1.right=t2.right   
        t1.val+=t2.val
        helper(t1,t2)
        return t1
```
