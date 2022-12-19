
### 暴力排序

时间复杂度$O(NlogN)$，内置方法使用了c扩展，暴力排序也不慢，甚至可以强行两行。

```python []
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        ans = []
        def f(r):
            if r:
                ans.append(r.val)
                f(r.left)
                f(r.right)
        return f(root1) or f(root2) or sorted(ans)
```
```python []
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        ans, f = [], lambda r: r and (f(r.left) or ans.append(r.val) or f(r.right))
        return f(root1) or f(root2) or sorted(ans)
```

```python []
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        f = lambda r: r and [*f(r.left), r.val, *f(r.right)] or []
        return sorted([*f(root1), *f(root2)])
```
```python []
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        f = lambda r: r and [*f(r.left), r.val, *f(r.right)] or []
        return heapq.merge(f(root1), f(root2))
```



### 比较输出

逆中序遍历获得两个逆序数组，然后比较尾部来输出，时间复杂度$O(N)$，正序也可以，就是纯数组的`pop(0)`理论上比`pop()`慢一些，改成队列`deque`也可以，效率和纯数组的逆序差不多，就是要额外引入`collections`模块。

```python []
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        a, b = [], []
        def f(r, t):
            if r:
                f(r.right, t)
                t.append(r.val)
                f(r.left, t)
        f(root1, a) or f(root2, b)
        while a and b:
            yield a.pop() if a[-1] < b[-1] else b.pop()
        yield from reversed(a or b)
```
```python []
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        a, b = collections.deque(), collections.deque()
        def f(r, t):
            if r:
                f(r.left, t)
                t.append(r.val)
                f(r.right, t)
        f(root1, a) or f(root2, b)
        while a and b:
            yield a.popleft() if a[0] < b[0] else b.popleft()
        yield from a or b
```
```python []
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        a, b = [], []
        def f(r, t):
            if r:
                f(r.left, t)
                t.append(r.val)
                f(r.right, t)
        f(root1, a) or f(root2, b)
        while a and b:
            yield a.pop(0) if a[0] < b[0] else b.pop(0)
        yield from a or b
```