思路是DFS找到根节点到`p, q`的路径, 注意最好是一个`path`来递归调用, 不要写
```
helper(node.left, path + [node])
```
这样会不断拷贝生成新的`path`大大减慢运行速度.

```python
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        paths = []

        def helper(node, path):
            if not node:
                return
            if node == p or node == q:
                paths.append(path + [node])
                return
            path.append(node)
            helper(node.left, path)
            helper(node.right, path)
            path.pop()

        helper(root, [])
        if len(paths) == 1:
            return paths[-1][-1]
        p1, p2 = paths[0], paths[1]
        n1, n2 = len(p1), len(p2)
        for i in range(min(n1, n2) -1, -1, -1):
            if p1[i] == p2[i]:
                return p1[i]
```

