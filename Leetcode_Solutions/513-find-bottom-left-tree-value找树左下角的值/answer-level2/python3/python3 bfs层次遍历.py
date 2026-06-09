### 解题思路
层次遍历，用一个变量更换最左边的值就行了，记住右边先入队列，这样如果左边有值会最后更新

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        from collections import deque
        queue = deque()
        queue.appendleft(root)

        res = 0
        while queue:
            n = len(queue)
            for _ in range(n):
                node = queue.pop()
                res = node.val

                if node.right:
                    queue.appendleft(node.right)

                if node.left:
                    queue.appendleft(node.left)

        return res
```