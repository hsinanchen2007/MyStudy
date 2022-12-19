```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.best=0
        
    def longestConsecutive(self, root: TreeNode) -> int:
        if not root:
            return 0
        if not hasattr(root,'inc'): 
            root.inc=1
        # if not hasattr(root,'dec'): 
        #     root.dec=1
        if root.left and root.left.val-root.val==1:
            root.left.inc=root.inc+1
        # if root.left and root.left.val-root.val==-1:
        #     root.left.dec=root.dec+1
        if root.right and root.right.val-root.val==1:
            root.right.inc=root.inc+1
        # if root.right and root.right.val-root.val==-1:
        #     root.right.dec=root.dec+1
        self.longestConsecutive(root.left)
        self.longestConsecutive(root.right)
        # self.best=max(self.best,root.inc,root.dec)
        self.best=max(self.best,root.inc)
        return self.best
```
