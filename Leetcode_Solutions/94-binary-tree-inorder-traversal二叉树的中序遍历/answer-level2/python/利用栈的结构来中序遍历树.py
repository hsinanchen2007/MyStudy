# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        a=[]
        cur=root
        res=[]
        while cur or len(a):#为什么要这个截止条件
            while cur:
                a.append(cur)
                cur=cur.left
            cur=a.pop()
            res.append(cur.val)
            cur=cur.right
        return res