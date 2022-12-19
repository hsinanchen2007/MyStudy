```
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return None
        stack = [root]
        res = []
        while stack:
            line = []
            for i in range(len(stack)):
                n = stack.pop(0)
                line.append(n.val)
                if n.left:
                    stack.append(n.left)
                if n.right:
                    stack.append(n.right)
            res.insert(0, line)
        return res
```
