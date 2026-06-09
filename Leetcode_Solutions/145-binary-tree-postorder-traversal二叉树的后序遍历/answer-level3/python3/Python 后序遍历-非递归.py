Code:
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        p=root
        stack=[];List=[]
        while stack or p:
            while p:
                stack.append(p)
                p=p.left if p.left!=None else  p.right
            pop=stack.pop()
            List.append(pop.val)
            if stack:
                if stack[-1].left==pop:
                    p=stack[-1].right
            else:
                p=None
        return List
        
```