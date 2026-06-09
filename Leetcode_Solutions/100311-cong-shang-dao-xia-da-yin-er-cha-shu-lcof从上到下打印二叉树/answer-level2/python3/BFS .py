### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        from collections import deque
        if not root:
            return []
        quque = deque()
        re = []
        quque.append(root)
        while quque:
            tmp = quque.popleft()
            if tmp:
                re.append(tmp.val)
                quque.append(tmp.left)
                quque.append(tmp.right)
        return re
            
```