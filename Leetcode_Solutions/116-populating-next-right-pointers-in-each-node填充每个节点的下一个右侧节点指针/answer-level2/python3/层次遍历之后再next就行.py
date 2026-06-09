### 解题思路
此处撰写解题思路

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return None
        # 这个题直接层次遍历找到每一层的所有节点，然后来指就行了
        res = []

        def helper(root,depth):
            if root:
                try:
                    res[depth].append(root)
                except:
                    res.append([root])
                depth += 1
                helper(root.left, depth)
                helper(root.right, depth)
        helper(root, 0)
        for i in range(len(res)):
            for j in range(len(res[i])):
                if j == len(res[i]) - 1:
                    res[i][j].next = None
                else:
                    res[i][j].next = res[i][j + 1]
        return root
```