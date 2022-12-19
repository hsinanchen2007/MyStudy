### 解题思路
此处撰写解题思路

第一次除汉诺塔以外写递归，感觉官方总结的很好，复习了语法和递归

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        return self.isMirror(root,root)
    def isMirror(self,t1: TreeNode,t2: TreeNode):
        if (t1==None and t2==None):
            return True
        if (t1==None or t2==None):
            return False
        return (t1.val==t2.val) and (self.isMirror(t1.left,t2.right)) and (self.isMirror(t1.right,t2.left))

```