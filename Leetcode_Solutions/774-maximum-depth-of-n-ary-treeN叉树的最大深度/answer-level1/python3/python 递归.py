```
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if root is None:
            return 0
        children = [self.maxDepth(x) for x in root.children ]
        if children:
            return 1+max(children)
        return 1
```