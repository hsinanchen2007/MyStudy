    # Definition for a binary tree node.
    # class TreeNode:
    #     def __init__(self, x):
    #         self.val = x
    #         self.left = None
    #         self.right = None

    class Solution:
        #方法一：直接中序遍历判断
        def isValidBST(self,root:TreeNode)->bool:
            if not root:
                return True
            p = root 
            stack = []
            pre = None
            while p or stack:
                while p:
                    stack.append(p)
                    p = p.left
                p = stack.pop()
                if pre and p.val <= pre.val:
                    return False
                pre = p
                p = p.right
            return pre
                