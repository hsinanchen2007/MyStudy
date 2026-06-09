```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        self.pre=None;
        self.mi=100;
        def inOrder(root):
            if (root):
                inOrder(root.left);
                if (self.pre):
                    self.mi=min(self.mi,root.val-self.pre.val);
                self.pre=root;
                inOrder(root.right);
        inOrder(root);
        return self.mi
```
