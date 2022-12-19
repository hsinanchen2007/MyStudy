```
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """
        global ans
        ans = 1
        def dfs(root, deep):
            if root.children is []:
                return
            global ans
            if deep>=ans:
                ans = deep + 1
            for child in root.children:
                dfs(child, deep+1)
        if root is None:
            return 0
        dfs(root, 0)
        return ans
```
