- 由于是到叶节点的距离，所以单空节点一定不是距离结算点

```py
class Solution:
    def minDepth(self, root: TreeNode) -> int:

        def get_min_depth(node):
            if node is None:
                return 1e9
            if node.left is None and node.right is None:
                return 1
            return min(get_min_depth(node.left), get_min_depth(node.right)) + 1
    
        return get_min_depth(root) if root else 0
```