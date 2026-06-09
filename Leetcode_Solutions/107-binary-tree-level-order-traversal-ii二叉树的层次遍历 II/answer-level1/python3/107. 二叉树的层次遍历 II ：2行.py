dfs

```python []
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        d = collections.defaultdict(list)
        def f(r, i):
            if r:
                d[i].append(r.val)
                f(r.left, i + 1)
                f(r.right, i + 1)
        f(root, 0)
        return [*d.values()][:: -1]
```
```python []
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        d = collections.defaultdict(list)
        def f(r, i):
            if r:
                d[i].append(r.val)
                f(r.left, i + 1)
                f(r.right, i + 1)
        f(root, 0)
        return reversed(d.values())
```


bfs
```python []
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        d = root and [root]
        ans = collections.deque()
        while d:
            ans.appendleft([t.val for t in d])
            d = [r for t in d for r in (t.left, t.right) if r]
        return ans
```

```python []
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        ans, d = [], root and [root]
        while d:
            ans.insert(0, [t.val for t in d])
            d = [r for t in d for r in (t.left, t.right) if r]
        return ans
```

```python []
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        ans, d = [], root and [root]
        while d:
            ans.append([t.val for t in d])
            d = [r for t in d for r in (t.left, t.right) if r]
        return ans[:: -1]
```


```python []
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        def f(d):
            if d:
                yield from f([r for t in d for r in (t.left, t.right) if r])
                yield [r.val for r in d]
        return f(root and [root])
```


```python []
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        f = lambda d: d and ((yield from f([r for t in d for r in (t.left, t.right) if r])) or (yield [r.val for r in d]))
        return f(root and [root])
```

![image.png](https://pic.leetcode-cn.com/d011088de2bb4729b418b69dfd6d7d831380da9fb104cb08b0241344b7d26d4f-image.png)
