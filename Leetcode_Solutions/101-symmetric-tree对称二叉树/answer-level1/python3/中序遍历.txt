```
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        nodes = []

        def inorder_walk(node, pos=None):
            if node:
                inorder_walk(node.left, 'lt')
                nodes.append((node.val, pos))
                inorder_walk(node.right, 'rt')

        inorder_walk(root, 'root')
        p, q = 0, len(nodes) - 1
        while p < q:
            if nodes[p][0] != nodes[q][0] or nodes[p][1] == nodes[q][1]:
                return False
            p, q = p + 1, q - 1
        return True
```
