```python
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if not root: return 0
        stack = [root]
        hashmap = {None: 0}
        MAX = -1
        while stack:
            node = stack.pop()
            if node.left in hashmap and node.right in hashmap:
                hashmap[node] = max(hashmap[node.left], hashmap[node.right]) + 1
                D = hashmap[node.left] + hashmap[node.right]
                MAX = max(MAX, D)
            else:
                stack.append(node)
                if node.right:
                    stack.append(node.right)
                if node.left:
                    stack.append(node.left)
        return MAX
```