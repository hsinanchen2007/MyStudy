```python
from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if not root: return []

        res = []
        stack = [root]

        while stack:
            if not stack[-1].left and not stack[-1].right:
                cur = stack.pop()
                res.append(cur.val)
                if not stack:
                    break
            last = stack[-1]
            if last.right:
                stack.append(last.right)
                last.right = None
            if last.left:
                stack.append(last.left)
                last.left = None

        return res

    def postorderTraversal1(self, root: TreeNode) -> List[int]:
        res = []

        def recur(root: TreeNode) -> None:
            if not root: return
            recur(root.left)
            recur(root.right)
            res.append(root.val)
        recur(root)

        return res
```