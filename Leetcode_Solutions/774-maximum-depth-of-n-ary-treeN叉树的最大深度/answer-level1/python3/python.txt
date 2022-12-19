### 解题思路
递归和迭代
### 代码
```
```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
迭代

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        deque=collections.deque()
        deque.append(root)
        res=0
        if not root:
            return 0
        while deque:
            count=len(deque)
            res+=1
            for i in range(count):
                node=deque.popleft()
                for i in node.children:
                    deque.append(i)
        return res
```
```
递归
        if not root:
            return 0
        res=0
        for child in root.children:
            res=max(self.maxDepth(child),res)
        return res+1      
```
