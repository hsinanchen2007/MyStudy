Code
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        p=root
        stack=[] ;List=[]
        while stack or p:
            while p:   
                stack.append(p)
                p=p.left
            pop=stack.pop()
            List.append(pop.val)
            p=pop.right
        return List       
```