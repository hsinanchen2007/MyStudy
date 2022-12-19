```
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        else:
            dq = [root]
            while dq:
                node = dq.pop(0)
                if node.left: dq.append(node.left)
                if node.right: dq.append(node.right)
                node.left, node.right = node.right, node.left
        return root
```
