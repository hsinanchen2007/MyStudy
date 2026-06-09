空间$O(N)$

```python []
class Solution:
    def flatten(self, root: TreeNode) -> None:
        roots = []
        def f(r):
            if r:
                roots.append(r)
                f(r.left)
                f(r.right)
        f(root)
        r = TreeNode(0) 
        for root in roots:
            r.right = root
            r = r.right
            root.left = None
```

空间$O(1)$

```python []
class Solution:
    nextTree = None
    def flatten(self, root: TreeNode) -> None:
        if root:
            self.flatten(root.right)
            self.flatten(root.left)
            self.nextTree, root.left, root.right = root, None, self.nextTree
```

![image.png](https://pic.leetcode-cn.com/43da999ce54405a0777070634c1505a7bed6249fcbeb2683a883a74418ce197b-image.png)
