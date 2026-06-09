
```python []
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        d = collections.defaultdict(collections.deque)
        def f(r, i):
            if r:
                d[i].appendleft(r.val) if i % 2 else d[i].append(r.val)
                f(r.left, i + 1)
                f(r.right, i + 1)
        f(root, 0)
        return d.values()
```