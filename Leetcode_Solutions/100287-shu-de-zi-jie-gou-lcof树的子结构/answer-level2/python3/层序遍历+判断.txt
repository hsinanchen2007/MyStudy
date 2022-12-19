```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if(not B):
            return False
        q1 = []
        q2 = []
        q1.append(A)
        t = None
        while(q1):
            t = q1.pop(0)
            if(t.val == B.val):
                break
            if(t.left): q1.append(t.left)
            if(t.right): q1.append(t.right)
        if(t.val != B.val):
            return False
        q1 = []
        q1.append(t)
        q2.append(B)
        while(q1 and q2):
            t1 = q1.pop(0)
            t2 = q2.pop(0)
            if(t1.val != t2.val):
                return False
            if(t1.left): q1.append(t1.left)
            if(t1.right): q1.append(t1.right)
            if(t2.left): q2.append(t2.left)
            if(t2.right): q2.append(t2.right)
        if(not q2):
            return True
        return False
```
