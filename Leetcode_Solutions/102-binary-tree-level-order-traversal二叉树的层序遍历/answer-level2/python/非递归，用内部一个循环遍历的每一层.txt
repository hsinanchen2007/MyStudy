`from collections import deque
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        res = []
        queue = deque()
        queue.append(root)
        while queue:
            level_item = []
            for i in range(len(queue)):
                iout = queue.popleft()
                level_item.append(iout.val)
                if iout.left:
                    queue.append(iout.left) 
                if iout.right:
                    queue.append(iout.right) 
            res.append(level_item)
        return res`