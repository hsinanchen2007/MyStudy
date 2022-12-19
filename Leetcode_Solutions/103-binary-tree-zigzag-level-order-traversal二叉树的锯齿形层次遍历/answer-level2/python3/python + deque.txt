```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        # double queue
        if root is None: return []
        queue = collections.deque([root])
        layer = 1
        res = []
        while queue:
            tempRes, queueLength = [], len(queue)
            if layer & 1 == 1:
                for i in range(queueLength):
                    cur = queue.pop()
                    tempRes.append(cur.val)
                    if cur.left:
                        queue.appendleft(cur.left)
                    if cur.right:
                        queue.appendleft(cur.right)
            else:
                for i in range(queueLength):
                    cur = queue.popleft()
                    tempRes.append(cur.val)
                    if cur.right:
                        queue.append(cur.right)
                    if cur.left:
                        queue.append(cur.left)
            layer += 1
            res += [tempRes]
        return res
```