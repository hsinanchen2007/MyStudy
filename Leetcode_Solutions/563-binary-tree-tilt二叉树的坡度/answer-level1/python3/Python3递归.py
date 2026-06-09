```
class Solution:
    def __init__(self):
        self.ans = 0

    def findTilt(self, root: TreeNode) -> int:

        def find_sum(node: TreeNode):
            if not node: return 0
            l = find_sum(node.left)
            r = find_sum(node.right)
            self.ans += abs(l-r)
            return node.val + l + r
        
        find_sum(root)
        return self.ans
```
