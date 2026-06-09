```
def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return root

        queue = [root]

        while queue:
            node = queue.pop(0)
            # 结点非空则翻转左右孩子
            if node:
                queue.append(node.left)
                queue.append(node.right)
                node.left, node.right = node.right, node.left
        return root
```
