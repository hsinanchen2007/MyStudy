
```python []
class Solution:
    def maxDepth(self, root: Node):
        if root is None:
            return 0
        if root.children is None:
            return 1
        maxDepth = 1
        for child in root.children:
            tempDepth = maxDepth(child) + 1
            if tempDepth > maxDepth:
                maxDepth = tempDepth
        return maxDepth

