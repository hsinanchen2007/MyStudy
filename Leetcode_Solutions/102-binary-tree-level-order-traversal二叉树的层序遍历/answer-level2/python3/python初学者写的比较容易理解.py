# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        n = 0
        out = []
        def maxDepth(root):
            if root==None:
                return 0 
            else:
                return 1+max(maxDepth(root.left),maxDepth(root.right))
        length = maxDepth(root)
        [out.append([]) for _ in range(length)] 
        def dns(root:TreeNode, n:int, out):
            out[n].append(root.val)
            if not (root.right or root.left):
                return out 
            if root.right is None:
                return dns(root.left, n+1 , out)
            if root.left is None:
                return dns(root.right, n+1, out)
            else:
                return dns(root.left, n+1, out) and dns(root.right, n+1, out)
        return dns(root,n,out)