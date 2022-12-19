### 解题思路
**1。迭代**

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        if not root:return 0
        cur_depth = 0
        max_depth = 0
        q = [(1,root)]
        while q:
            cur_depth,r = q.pop()
            if r:
                max_depth = max(cur_depth,max_depth)
                q.append((cur_depth + 1,r.left))
                q.append((cur_depth + 1,r.right))
        return max_depth

```
**2.递归**
### 代码

```python
class Solution(object):
    def maxDepth(self, root):
        if not root:
            return 0
        return 1 + max(self.maxDepth(root.left),self.maxDepth(root.right))
```



```


```

```