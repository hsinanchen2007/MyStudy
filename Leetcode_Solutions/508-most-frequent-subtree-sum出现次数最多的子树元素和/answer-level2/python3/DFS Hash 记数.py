DFS 一下记录所有子树和到 Hash 里，然后处理一下 Hash 找计数 Top 1 所有的元素即可。

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.h = {}
        
    def _sum(self, rt):
        if not rt: return 0
        tmp = rt.val 
        tmp += self._sum(rt.left)
        tmp += self._sum(rt.right)
        self.h[tmp] = 1 if not self.h.get(tmp) else self.h[tmp] + 1
        return tmp
            
    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        if not root: return []
        if root.left is None and root.right is None: return [root.val]
        #print(root)
        self._sum(rt=root)
        #print(self.h)
        hh = sorted(self.h.items(), key=lambda i: i[1], reverse=True)
        return [hh[i][0] for i in range(len(hh)) if hh[i][1] == hh[0][1]]
```