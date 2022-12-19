### 解题思路
此处撰写解题思路

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if not root:return
        def dfs(rt):
            if rt.left==rt.right==None:return rt,rt
            elif rt.left==None:
                ll,rr = dfs(rt.right)
                rt.right = ll
                ll.left = rt
                return rt,rr
            elif rt.right==None:
                ll,rr = dfs(rt.left)
                rt.left = rr
                rr.right = rt
                return ll,rt
            else:
                ll,rl = dfs(rt.left)
                lr,rr = dfs(rt.right)
                rt.left = rl
                rl.right = rt
                rt.right = lr
                lr.left = rt
                return ll,rr
        ll,rr = dfs(root)
        ll.left = rr
        rr.right = ll
        return ll

```