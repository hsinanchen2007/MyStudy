```
class Solution:
    def __init__(self):
        self.best=0.0
        
    def maximumAverageSubtree(self, root):
        root.total,root.count=root.val,1.0
        if root.left:
            self.best=max(self.maximumAverageSubtree(root.left),self.best)
            root.total+=root.left.total
            root.count+=root.left.count
        if root.right:
            self.best=max(self.maximumAverageSubtree(root.right),self.best)
            root.total+=root.right.total
            root.count+=root.right.count
        return max(self.best,root.total/root.count)
```
