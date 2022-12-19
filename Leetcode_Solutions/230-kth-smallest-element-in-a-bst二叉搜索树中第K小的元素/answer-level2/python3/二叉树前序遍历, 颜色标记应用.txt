### 解题思路
52 ms, faster than 57.66% of Python3 

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        s, c = [root], 0
        while s:
            n = s.pop()
            if n is None: continue
            if isinstance(n, int):
                c += 1
                if c==k:
                    return n
                continue
            else:
                s.extend([n.right, n.val, n.left])



```

标准前序, 更快些28ms
```
def kthSmallest(self, root: TreeNode, k: int) -> int:
        
        stack = []
        
        while True:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            k -= 1
            if not k:
                return root.val
            root = root.right
```