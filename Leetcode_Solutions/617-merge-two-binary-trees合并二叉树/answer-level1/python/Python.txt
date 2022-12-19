### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        if t1==None and t2==None:
            return None
        if t1==None:
            next=TreeNode(t2.val)
            if t2.left!=None:
                next.left=self.mergeTrees(None,t2.left)
            else:
                next.left==None
            if t2.right!=None:
                next.right=self.mergeTrees(None,t2.right)
            else:
                next.right==None
            return next
        elif t2==None:
            next=TreeNode(t1.val)
            if t1.left!=None:
                next.left=self.mergeTrees(t1.left,None)
            else:
                next.left==None
            if t1.right!=None:
                next.right=self.mergeTrees(t1.right,None)
            else:
                next.right==None   
            return next
        else:
            next=TreeNode(t1.val+t2.val)
            next.left=self.mergeTrees(t1.left,t2.left)
            next.right=self.mergeTrees(t1.right,t2.right)   
            return next                    

```