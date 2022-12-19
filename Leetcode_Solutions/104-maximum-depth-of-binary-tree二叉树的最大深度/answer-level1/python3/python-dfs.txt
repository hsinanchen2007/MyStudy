```
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        stack=[]
        if root is not None: stack.append((1,root))
        depth = 0
        while stack!=[]:
            currentDepth,root = stack.pop()
            if root is not None:
                depth = max(depth,currentDepth)
                stack.append((currentDepth+1,root.left))
                stack.append((currentDepth+1,root.right))
        return depth
```
