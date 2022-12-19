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
    def largestValues(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        queue = [root]
        re, temp = [], []
        while queue:
            n = len(queue)
            for i in range(n):
                cur = queue.pop()
                temp.append(cur.val)
                if cur.left:
                    queue.insert(0, cur.left)
                if cur.right:
                    queue.insert(0, cur.right)
            re.append(max(temp))
            temp = []
        return re
```