
```python3
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        st = [root]
        while st:
            node = st.pop()
            if node:
                node.right, node.left = node.left, node.right
                st += [node.right, node.left]
        return root
```