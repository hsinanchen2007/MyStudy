```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if not root:
            return []
        return self.solve(root,sum)
    
    def solve(self,node,target):
        new_target = target-node.val
        if not node.left and not node.right:
            if new_target==0:
                return [[node.val]]
            else:
                return []
        else:
            res = []
            if node.left:
                for x in self.solve(node.left,new_target):
                    res.append([node.val]+x)
            if node.right:
                for x in self.solve(node.right,new_target):
                    res.append([node.val]+x)
        return res
                
        
        
        
```
