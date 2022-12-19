```
class Solution:
    def tree2str(self, t: TreeNode) -> str:
        if t == None:
            return ''
        if not (t.left or t.right):
            return str(t.val)
        elif t.left and t.right:
            return str(t.val)+'(' + self.tree2str(t.left) + ')('+self.tree2str(t.right)+')'
        elif t.left:
            return str(t.val)+'('+self.tree2str(t.left)+')'
        elif t.right:
            return str(t.val)+'()('+self.tree2str(t.right)+')'
```

