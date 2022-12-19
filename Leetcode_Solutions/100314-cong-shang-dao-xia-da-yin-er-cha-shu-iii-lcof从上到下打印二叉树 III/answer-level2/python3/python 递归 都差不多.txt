# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        def helper(root,level):
            if not root:
                return
            if len(res)==level:
                res.append([])
            if level%2==0:
                res[level].append(root.val)
            else:
                res[level].insert(0,root.val)
            helper(root.left,level+1)
            helper(root.right,level+1)
        helper(root,0)