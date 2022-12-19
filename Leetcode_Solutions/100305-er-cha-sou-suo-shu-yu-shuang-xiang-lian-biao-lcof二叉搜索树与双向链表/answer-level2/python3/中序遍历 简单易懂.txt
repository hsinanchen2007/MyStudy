"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if not root:
            return None
        res = []
        def helper(root):
            if not root:
                return None
            helper(root.left)
            res.append(root)
            helper(root.right)
        helper(root)
        head = res[0]
        if len(res)==1:
            head.left = head
            head.right = head
            return head
        if len(res)>1:
                head.left = res[-1]
                head.right = res[1]
                res[-1].left = res[-2]
                res[-1].right = head
        for i in range(1,len(res)-1):
                res[i].left = res[i-1]
                res[i].right = res[i+1]
        return head