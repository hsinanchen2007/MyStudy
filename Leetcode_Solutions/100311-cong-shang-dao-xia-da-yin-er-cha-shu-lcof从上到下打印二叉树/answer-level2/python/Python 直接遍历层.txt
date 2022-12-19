```python
class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        result = list()
        current_layer = [root]
        while current_layer:
            next_layer = list()
            this_layer_val = list()
            for node in current_layer:
                if node is None:
                    continue
                next_layer.append(node.left)
                next_layer.append(node.right)
                this_layer_val.append(node.val)
            if this_layer_val:
                result += this_layer_val
            current_layer = next_layer
        return result
```
