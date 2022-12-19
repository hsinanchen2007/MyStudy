### 递归

额外空间为树的深度，即递归栈的深度

```python []
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        ans, prev = True, -float('inf')
        def f(r):
            nonlocal ans, prev
            if ans and r:
                f(r.left)
                if r.val <= prev:
                    ans = False
                prev = r.val
                f(r.right)
        root and f(root)
        return ans
```

### 迭代

额外空间为自建栈的深度

```python []
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        prev, stack = -float('inf'), root and [root]
        while root or stack:
            if root:
                stack.append(root)
                root = root.left
            else:
                root = stack.pop()
                if stack and root.val <= prev:
                    return False
                prev = root.val
                root = root.right
        return True
```

### 暴力遍历

额外空间$O(N)$

```python []
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        a, f = [], lambda r: r and (f(r.left) or a.append(r.val) or f(r.right))
        return f(root) or all(a[i - 1] < a[i] for i in range(1, len(a)))
```
```python []
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        a, f = [], lambda r: r and (f(r.left) or a.append(r.val) or f(r.right))
        return f(root) or all(a[i] < j for i, j in enumerate(a[1: ]))
```
