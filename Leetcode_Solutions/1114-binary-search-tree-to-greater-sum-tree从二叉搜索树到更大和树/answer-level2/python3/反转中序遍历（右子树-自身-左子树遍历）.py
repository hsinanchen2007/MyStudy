右子树-自身-左子树，遍历到的节点值为前节点➕自身

```

class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.order(root, 0)
        return root
    def order(self, node, num):
        if node is None:
            return num
        if node.right is not None:
            num = self.order(node.right, num)
        num += node.val
        node.val = num 
        if node.left is not None:
            num = self.order(node.left, num)
        return num
```