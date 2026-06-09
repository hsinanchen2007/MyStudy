```
class Solution:
    def upsideDownBinaryTree(self, root: TreeNode) -> TreeNode:
        if root is None: 
            return root
        elif root.left is None:
            return root
        else:
            rootLeft = root.left
            rootRight = root.right
            resRoot = self.upsideDownBinaryTree(rootLeft)
            rootLeft.left = rootRight
            rootLeft.right = root
            root.left = None
            root.right = None
            return resRoot
```

