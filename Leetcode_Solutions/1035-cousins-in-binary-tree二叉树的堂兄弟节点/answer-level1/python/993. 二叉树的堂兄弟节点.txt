### 解题思路
**1.哈希表 递归 官方题解**

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isCousins(self, root, x, y):
        parent = {}
        depth = {}
        def dfs(root,par = None):
            if root:
                depth[root.val] = 1 + depth[par.val] if par else 0
                parent[root.val] = par
                dfs(root.left,par = root)
                dfs(root.right,par = root)
        dfs(root)
        return depth[x] == depth[y] and parent[x] != parent[y]

```
### 解题思路
**2.哈希表 迭代**
```python
class Solution(object):
    def isCousins(self, root, x, y):
        parent = {}
        par = None
        q = [(1,root,par)]
        while q:
            level,root,par = q.pop(0)
            if root:
                parent[root.val] = par
                if root.val == x:
                    level_x = level
                    parent_x = parent[root.val]
                if root.val == y:
                    level_y = level
                    parent_y = parent[root.val]
                par = root
                q.append((level+1,root.left,par))
                q.append((level+1,root.right,par))
        return level_x == level_y and parent_x != parent_y
```
