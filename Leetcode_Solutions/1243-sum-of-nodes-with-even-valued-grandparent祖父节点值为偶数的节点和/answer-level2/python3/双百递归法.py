```
class Solution:
    def __init__(self):
        self.total = 0
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        if root.val % 2 == 0:
            if root.left:
                if root.left.left:
                    self.total += root.left.left.val
                if root.left.right:
                    self.total += root.left.right.val
                self.sumEvenGrandparent(root.left)
            if root.right:
                if root.right.left:
                    self.total += root.right.left.val
                if root.right.right:
                    self.total += root.right.right.val
                self.sumEvenGrandparent(root.right)
            pass
        else:
            if root.left:
                self.sumEvenGrandparent(root.left)
            if root.right:
                self.sumEvenGrandparent(root.right)
        return self.total
```
