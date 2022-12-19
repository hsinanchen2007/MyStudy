# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sumval: int) -> bool:

        def depthSearch(root,sumval,target):
            if not root:
                return False
        
            sumval += root.val
            if not any([root.left,root.right]):
                if sumval == target:
                    return True
                else:
                    return False

            l = depthSearch(root.left,sumval,target)
            r = depthSearch(root.right,sumval,target)
            return any([l,r])
        return depthSearch(root,0,sumval)