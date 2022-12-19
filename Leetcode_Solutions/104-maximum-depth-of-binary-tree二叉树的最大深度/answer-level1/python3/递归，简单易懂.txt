```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root==None:
            return 0
        self.maxdepth=1
        depth=1
        o_depth=depth
        if root.left:
            depth+=1
            self.findleft(depth,root.left)
        if root.right:
            o_depth+=1
            self.findright(o_depth,root.right)
            
        return self.maxdepth
    
    def findleft(self,depth,root):
        if depth>self.maxdepth:
            self.maxdepth=depth
        
        o_depth=depth
        if root.left:
            depth+=1
            self.findleft(depth,root.left)
        if root.right:
            o_depth+=1
            self.findright(o_depth,root.right)
    def findright(self,depth,root):
        if depth>self.maxdepth:
            self.maxdepth=depth
            
        o_depth=depth
        if root.left:
            depth+=1
            self.findleft(depth,root.left)
        if root.right:
            o_depth+=1
            self.findright(o_depth,root.right)
```
