```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root==None:
            return 0
        list1=[(root,1)]
        while list1:
            now_node,now_step=list1.pop(0)
            
            if now_node.left==None and now_node.right==None:
                return now_step
            
            if now_node.left:
                list1.append((now_node.left,now_step+1))
            if now_node.right:
                list1.append((now_node.right,now_step+1))
```
