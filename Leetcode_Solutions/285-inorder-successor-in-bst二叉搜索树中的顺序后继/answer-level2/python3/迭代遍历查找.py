```
class Solution:
    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        stack = []
        n = root
        found = -1
        while n or stack:
            while n:
                stack.append(n)
                if n == p:
                    found = 0
                    break
                n = n.left
            n = stack.pop()
            if found == 1:
                return n
            elif found == 0:
                found = 1
            n = n.right

```
