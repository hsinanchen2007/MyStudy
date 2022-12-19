```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        depth = 1
        queue = [root, ]
        while queue:
            lens = len(queue)
            for i in range(lens):
                p = queue.pop(0)#切记要先取出
                if p.left is None and p.right is None:
                    return depth
                if p.left:
                    queue.append(p.left)
                if p.right:
                    queue.append(p.right)
            depth += 1
        return depth
```
