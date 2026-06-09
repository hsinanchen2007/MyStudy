### 解题思路
**1.递归**

### 代码

```python
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
class Solution(object):
    def maxDepth(self, root):
        if root is None: 
            return 0 
        elif not root.children:
            return 1
        else: 
            depth = [self.maxDepth(c) for c in root.children]
            return max(depth) + 1 
```
### 解题思路
**2.迭代**

### 代码

```python
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
class Solution(object):
    def maxDepth(self, root):
        if root is None: 
            return 0 
        stack = [(1,root)]
        max_depth = 1
        while stack:
            level,root = stack.pop()
            if root:
                max_depth = max(max_depth,level)
                if not root.children:continue
                for c in root.children:
                    if c :
                        stack.append((level + 1,c))
        return max_depth
```