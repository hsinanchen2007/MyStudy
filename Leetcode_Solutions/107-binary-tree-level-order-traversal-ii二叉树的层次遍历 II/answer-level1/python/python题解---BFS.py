```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None:
            return []
        l = [root]
        result = []
        out = []
        while l:
            #out.append(l.val)
            out = []
            new = []
            for i in l:
                out.append(i.val)
                if i.left:
                    new.append(i.left)
                if i.right:
                    new.append(i.right)
            l = new
            result.append(out)
        return result[::-1]
```
