递归解法 注意判断node是否为空
```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def helper(self,node,res):
        if node:
            if node.left:
                self.helper(node.left,res)
            res.append(node.val)
            if node.right:
                self.helper(node.right,res)
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res=[]
        self.helper(root,res)
        return res

```
