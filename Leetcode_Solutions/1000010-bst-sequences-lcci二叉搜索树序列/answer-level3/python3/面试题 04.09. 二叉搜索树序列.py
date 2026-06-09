### 解题思路

把树的值按结构存进了字典，组合展开。

### 代码

```python []
class Solution:
    def BSTSequences(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return [[]]
        d = {}
        def f(r):
            if r:
                d[r.val] = []
                r.left and (d[r.val].append(r.left.val) or f(r.left))
                r.right and (d[r.val].append(r.right.val) or f(r.right))
        f(root)
        n = len(d)
        q = [[[root.val], {root.val}]]
        while len(q[0][0]) < n:
            t = []
            for p, c in q:
                for r in p:
                    for v in d[r]:
                        if v not in c:
                            t.append([p + [v], c | {v}])
            q = t
        return [r for r, _ in q]
```