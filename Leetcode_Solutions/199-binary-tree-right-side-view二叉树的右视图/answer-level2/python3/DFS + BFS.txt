## 思路：

思路一：DFS

思路二：BFS

看代码很好理解的。

## 代码：

思路一：

```python
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        res = []

        def dfs(root, depth):
            if not root:
                return 
            if len(res) <= depth:
                res.append(0)
            res[depth] = root.val
            dfs(root.left, depth + 1)
            dfs(root.right, depth + 1)
        
        dfs(root, 0)
        return res
```

思路二：

```python
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root: return []
        res = []

        def bfs(root):
            queue = [root]
            while queue:
                nxt = []
                res.append(queue[-1].val)
                for node in queue:
                    if node.left:
                        nxt.append(node.left)
                    if node.right:
                        nxt.append(node.right)
                queue = nxt
        
        bfs(root)
        return res
```

