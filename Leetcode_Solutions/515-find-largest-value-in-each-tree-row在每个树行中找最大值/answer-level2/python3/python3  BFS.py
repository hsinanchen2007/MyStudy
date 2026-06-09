# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import math
class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        if not root:return []
        frontier = [root]
        res = []
        cur_max = root.val
        while frontier:
            for i in range(len(frontier)):
                node = frontier.pop(0)
                if node.val > cur_max:
                    cur_max = node.val
                if node.left:
                    frontier.append(node.left)
                if node.right:
                    frontier.append(node.right)
            res.append(cur_max)
            cur_max = - math.inf
        return res 