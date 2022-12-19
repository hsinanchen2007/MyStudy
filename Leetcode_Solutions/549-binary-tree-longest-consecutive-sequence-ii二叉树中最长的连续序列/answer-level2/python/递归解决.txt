
对于以root为根的树来说，符合条件的path可以分为两类：一类是不经过root的，一类是经过root的。不经过root的可以直接通过对其左子树和右子树的递归调用获得。经过root的有两种：一种是在其左子树上由下到上连续递增到root之后，在其右子树上由上到下连续递增；一种是在其左子树上由下到上连续递减到root之后，在其右子树上由上到下继续连续递减。我们取所有可能类型的path的最长长度即可。


```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def longestConsecutive(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def helper(root):
            incr,decr = 0,0
            for child in [root.left,root.right]:
                if not child:
                    continue
                cincr,cdecr = helper(child)
                if child.val == root.val - 1:
                    decr = max(decr,cdecr)
                elif child.val == root.val + 1:
                    incr = max(incr,cincr)
            self.ans = max(self.ans,incr + decr + 1)
            return incr + 1,decr + 1
        self.ans = 0
        if root:
            helper(root)
        return self.ans
```

