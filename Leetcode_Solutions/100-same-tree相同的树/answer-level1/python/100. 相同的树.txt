### 解题思路
广度优先搜索

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        if not p and not q:return True
        stack = [(p,q)]
        while stack:
            x,y = stack.pop()
            if not x and not y:continue
            if x and y and x.val == y.val:
                stack.append((x.left,y.left))
                stack.append((x.right,y.right))
            else:
                return False
        return True
```