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
    def getMinimumDifference(self, root: TreeNode) -> int:
        stack, node, temp, min_ = [], root, -1, float('inf')
        while node or stack:
            if node:
                stack.append(node)
                node = node.left
            else:
                node = stack.pop()
                if abs(node.val - temp) < min_ and temp >=0:
                    min_ = abs(node.val - temp)
                temp = node.val
                node = node.right
        return min_
        
            
```