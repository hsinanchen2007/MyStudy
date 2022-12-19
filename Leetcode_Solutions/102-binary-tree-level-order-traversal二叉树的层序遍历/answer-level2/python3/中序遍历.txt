```
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        record = {}

        def inorder_walk(node, depth=0):
            if node:
                inorder_walk(node.left, depth=depth+1)
                record[depth] = record.setdefault(depth, []) + [node.val]
                inorder_walk(node.right, depth=depth+1)

        inorder_walk(root)
        res = [record[key] for key in sorted(record.keys())]
        return res
```
