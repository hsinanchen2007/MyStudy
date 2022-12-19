```

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []
        res = []
        q = [root]
        h = 0
        while q:
            l = []
            h += 1
            for i in range(len(q)):
                n = q.pop(0)
                l.append(n.val)
                if n.left:
                    q.append(n.left)
                if n.right:
                    q.append(n.right)
            if h% 2 == 0:
                l.reverse()
            res.append(l)
        return res  
```
