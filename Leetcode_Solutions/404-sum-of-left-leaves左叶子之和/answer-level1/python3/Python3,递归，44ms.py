```
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        if not root: return 0
        return sum(self.helper(root, False, []))
    def helper(self, root, judge, lst):
        if not root:
            return 0
        if judge and not root.left and not root.right:
            lst.append(root.val)
        self.helper(root.left, True, lst)
        self.helper(root.right, False, lst)
        return lst
```
