```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        # Time complexity : O(N)
        # Space complexity: O(N)
        if root is None: return []
        stack = [(root, 0)]
        res = []
        while stack:
            cur, visCnt = stack.pop()
            if visCnt == 1:
                res.append(cur.val)
            else:
                visCnt += 1
                stack.append((cur, visCnt))
                if cur.right: stack.append((cur.right, 0))
                if cur.left: stack.append((cur.left, 0))
        return res
```