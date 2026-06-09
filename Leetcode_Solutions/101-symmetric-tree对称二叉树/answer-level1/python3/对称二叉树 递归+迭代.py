### 递归

```python
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:

        if root == None:
            return True
        def dfs(left, right):
            if left == None and right == None:
                return True
            if left == None or right == None:
                return False
            if left.val != right.val:
                return False
            return dfs(left.left, right.right) and dfs(left.right, right.left)
        return dfs(root.left, root.right)
```

### 迭代
```python
        que = [(root, root)]
        while que:
            t1, t2 = que.pop(0)
            if t1 == None and t2 == None:
                continue
            if t1 == None or t2 == None:
                return False
            if t1.val != t2.val:
                return False 
            que.append((t1.left, t2.right))
            que.append((t1.right, t2.left))
        return True
```