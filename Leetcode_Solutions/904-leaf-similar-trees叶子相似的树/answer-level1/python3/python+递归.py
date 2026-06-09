```
class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        def bianli(root, l):
            if not root:
                return
            if not root.left and not root.right:
                l.append(root.val)
            bianli(root.left, l)
            bianli(root.right, l)
            return l

        a = bianli(root1, [])
        b = bianli(root2,[])
        return a == b
```
