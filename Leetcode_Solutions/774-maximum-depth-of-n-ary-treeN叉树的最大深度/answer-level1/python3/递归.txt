### 解题思路
递归

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root:
            return 0
        elif not root.children:
            return 1
        else:
            #max = 0
            m = [self.maxDepth(x) for x in root.children]
            #for x in root.children:
            #    if self.maxDepth(x) > max:
            #        max = self.maxDepth(x)
                #res = max(res + self.maxDepth(x),res) ,错误写法，max后面第一个res也会累加
            return 1+max(m)
```