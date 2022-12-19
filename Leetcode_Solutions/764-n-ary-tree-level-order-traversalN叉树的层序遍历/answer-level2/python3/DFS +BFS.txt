思路一：DFS

```python
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:

        res = []

        def dfs(root, depth):
            if not root: return 
            if len(res) <= depth:
                res.append([])
            res[depth].append(root.val)
            for ch in root.children:
                dfs(ch, depth+1)
        
        dfs(root, 0)
        return res
```

思路二：BFS

```python
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:return []
        res = []
        
        def bfs(root):
            queue = [root]
            while queue:
                nxt = []
                tmp = []
                for node in queue:
                    tmp.append(node.val)
                    for ch in node.children:
                        nxt.append(ch)
                res.append(tmp)
                queue = nxt
        
        bfs(root)
        return res
```

