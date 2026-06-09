### 解题思路
使用队列层次遍历。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        
        grandfa = father = None
        res = 0
        deque = collections.deque()
        deque.append((root, father, grandfa))
        while deque:
            node, father, grandfa = deque.popleft()
            if node:
                if grandfa and grandfa.val % 2 == 0:
                    res += node.val
                deque.append((node.left, node, father))
                deque.append((node.right, node, father))

        return res
```