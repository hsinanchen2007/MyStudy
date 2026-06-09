bfs:
```
from collections import deque
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        if not root: return res
        q = deque([root])
        depth = 1
        while q:
            l = []
            for i in range(len(q)):
                temp = q.popleft()
                if depth&1:
                    l.append(temp.val)
                else :l.insert(0,temp.val)
                if temp.left: q.append(temp.left)
                if temp.right: q.append(temp.right)
            res.append(l)
            depth += 1
        return res
```
dfs:
```
from collections import deque
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        if not root: return res
        def helper(root,level):
            if len(res) == level:
                res.append([])
            if level&1:
                res[level].insert(0,root.val)
            else: res[level].append(root.val)
            if root.left:
                helper(root.left,level+1)
            if root.right:
                helper(root.right,level+1)
        helper(root,0)
        return res
```

