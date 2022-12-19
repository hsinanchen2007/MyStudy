# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        def helper(root,val):
            if not root:
                root = TreeNode(val)
                return root
            if root.val>val:
                if root.left == None:
                    node = TreeNode(val)
                    root.left = node
                    return root
                else:
                    helper(root.left,val)
            if root.val<val:
                if root.right == None:
                    node = TreeNode(val)
                    root.right = node
                    return root
                else:
                    helper(root.right,val)
        temp = root
        helper(temp,val)
        return root
        