### BFS:
q 为遍历到的层，p 为遍历到前一层，最后取p的和既可，时间复杂度$O(N)$，空间复杂度$O(W)$，其中$W$为二叉树的最大宽度。

### 代码

```python []
class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        q = [root]
        while q:
            q, p = [r for t in q for r in (t.left, t.right) if r], q
        return sum(r.val for r in p)
```
### DFS1:
遍历树，用字典记层次和，输出最后一层的值即可，时间复杂度$O(N)$，空间复杂度$O(H)$，其中$H$为二叉树的最大深度。

### 代码

```python []
class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        d = collections.defaultdict(int)
        def f(r, i):
            if r:
                d[i] += r.val
                f(r.left, i + 1)
                f(r.right, i + 1)
        return f(root, 0) or next(reversed(d.values()))
```

### DFS2:
用全局变量记录最大深度即对应的和，最后输出和即可，时间复杂度$O(N)$，空间复杂度$O(1)$。

### 代码

```python []
class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        s, h = 0, 0
        def f(r, i):
            if r:
                nonlocal s, h
                if i == h:
                    s += r.val
                elif i > h:
                    s, h = r.val, i
                f(r.left, i + 1)
                f(r.right, i + 1)
        return f(root, 0) or s
```



![image.png](https://pic.leetcode-cn.com/fb9c2f406583a9d5f4d32e1910558429dee49f4defd71913d7bc67024650c5e8-image.png)
