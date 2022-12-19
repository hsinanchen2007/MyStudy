# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        # method 1 递归
        # def depth(root):
        #     if not root:
        #         return 0
        #     if (not root.left) and (not root.right):
        #         return 1
        #     l = float('inf')
        #     r = float('inf')
        #     if root.left:
        #         l = depth(root.left)
        #     if root.right:
        #         r = depth(root.right)
        #     return min(l,r) + 1
        # return depth(root)

        # method2 广度遍历

        from collections import deque
        if not root:
            return 0
        q = deque()
        ret = 0
        q.append(root)

        while q:
            n = len(q)
            ret += 1
            for i in range(n):
                cur = q.popleft()
                if not any([cur.left,cur.right]):
                    return ret
                if cur.left:
                    q.append(cur.left)
                if cur.right:
                    q.append(cur.right)
        return ret
            


