思路一：DFS

```python
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        if not root: return []
        res = []
        def helper(root, tmp):
            if not root.left and not root.right:res.append(tmp + [str(root.val)]) 
            if root.left:helper(root.left, tmp + [str(root.val)])
            if root.right:helper(root.right, tmp + [str(root.val)])
        helper(root, [])
        return ["->".join(a) for a in res]     
```

思路二：BFS

```python
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        from collections import deque
        if not root: return []
        res = []
        queue = deque()
        queue.appendleft([root, []])
        while queue:
            node, tmp = queue.pop()
            if not node.left and not node.right:
                res.append("->".join(tmp + [str(node.val)]))
            if node.left:
                queue.appendleft([node.left, tmp + [str(node.val)]])
            if node.right:
                queue.appendleft([node.right, tmp + [str(node.val)]])
        return res
```

