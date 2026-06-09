**注意**：判断的顺序！
- p、q是否为空
- p、q左子树是否为空
- p、q右子树是否为空
- p、q值是否相同
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p == None and q == None:
            return True
        if p == None and q != None:
            return False
        if p != None and q == None:
            return False
        if p.left == None and q.left != None:
            return False
        if p.left != None and q.left == None:
            return False
        if p.right == None and q.right != None:
            return False
        if p.right != None and q.right == None:
            return False
        if p.val != q.val:
            return False
        if p.val == q.val:
            return self.isSameTree(p.right, q.right) and self.isSameTree(p.left, q.left)
```