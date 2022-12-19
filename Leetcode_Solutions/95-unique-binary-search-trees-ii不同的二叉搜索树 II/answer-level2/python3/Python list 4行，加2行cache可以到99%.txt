```
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x, left, right):
        self.val = x
        self.left = left
        self.right = right

class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        from functools import lru_cache
        if n<1: return []
        @lru_cache(None)
        def gen(l,r):
            return [TreeNode(root, left, right) for root in range(l,r+1) for left in gen(l,root-1) for right in gen(root+1, r)] or [None]
        return gen(1,n)
```
