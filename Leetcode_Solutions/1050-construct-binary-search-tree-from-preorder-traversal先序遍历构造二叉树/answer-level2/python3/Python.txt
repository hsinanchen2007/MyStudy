```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        if not preorder:return None
        root = TreeNode(None)
        for i in preorder:
            root = self.build_tree(root,i)
        return root
        
    
    def build_tree(self,node,i):
        if node is None or node.val is None:  #递归终止条件：空节点
            return TreeNode(i)
        
        if node.val > i:
            node.left = self.build_tree(node.left,i) #当前层级所需做：把小于自身的数bulid成TreeNode放在left分支 
        if node.val < i: 
            node.right = self.build_tree(node.right,i)
            
        return node        #返回给上一级：已经build完成的Node
```