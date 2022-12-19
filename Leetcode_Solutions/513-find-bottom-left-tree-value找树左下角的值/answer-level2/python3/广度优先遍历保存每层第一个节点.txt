```
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        last  = None
        stack = [root]
        while stack:
            last = stack[0].val
            for i in range(len(stack)):
                n = stack.pop(0)
                if n.left:
                    stack.append(n.left)
                if n.right:
                    stack.append(n.right)
        return last
```
