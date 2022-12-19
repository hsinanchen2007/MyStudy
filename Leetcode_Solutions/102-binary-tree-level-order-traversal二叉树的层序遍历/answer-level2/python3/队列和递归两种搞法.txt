### 解题思路 
此处撰写解题思路
`node = queue.popleft()`与`queue.append(node.left)`更配吆

### 代码 常规解法

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        levels = []
        if not root:
            return levels
        queue = deque([root,])
        while queue:
            level_len = len(queue)
            levels.append([])
            for i in range(level_len):
                node = queue.popleft()
                levels[-1].append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        return levels
```

### 递归解法
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        levels = []
        if not root:
            return levels
        def recur(root,level):
            if level == len(levels):
                levels.append([])
            levels[level].append(root.val)
            if root.left:
                recur(root.left,level+1)
            if root.right:
                recur(root.right,level+1)
        recur(root,0)
        return levels
```