### 解题思路
弱鸡解法

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root==None:
            return True
        if root.left==None and root.right==None:
            return True
        elif root.left!=None and root.right!=None:           
            return self.isMirror(root.left,root.right)
        else:
            return False
    def isMirror(self,p:TreeNode,q:TreeNode)->bool:
        if p==None and q==None:
            return True
        if p==None or q==None:
            return False
        return p.val==q.val and self.isMirror(p.left,q.right) and self.isMirror(p.right,q.left)


```