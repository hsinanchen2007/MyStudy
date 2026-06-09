```python3
import sys

class Solution:
    def __init__(self):
        self.clValue = sys.maxsize
        self.tag = 0

    def closestValue(self, root: TreeNode, target: float) -> int:
        # print(self.clValue, self.tag)
        if root == None:
            return self.tag
        else:
            if self.clValue > abs(root.val-target):
                self.clValue = abs(root.val-target)
                self.tag = root.val
        
        self.closestValue(root.left, target)
        self.closestValue(root.right, target)
        
        return self.tag

        

```