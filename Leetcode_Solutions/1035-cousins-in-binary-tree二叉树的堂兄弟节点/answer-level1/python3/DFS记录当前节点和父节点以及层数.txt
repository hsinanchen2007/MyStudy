
```
class Solution:

    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        _parent = {}
        _node = {}
        _local = {}

        def dfs_tree(node: TreeNode, parent: TreeNode, target_x: int, target_y: int, deepin: int):
            if not node:
                return
            if node.val == target_x or node.val == target_y:
                _node[node.val] = deepin
                _parent[node.val] = parent
                _local[node.val] = node
            dfs_tree(node.left, node, target_x, target_y, deepin + 1)
            dfs_tree(node.right, node, target_x, target_y, deepin + 1)

            pass

        if not root:
            return False

        dfs_tree(root, None, x, y, 0)

        return _node[x] == _node[y] and _parent[x] != _parent[y] and _local[x] != _parent[y] and _local[y] != _parent[x]

```